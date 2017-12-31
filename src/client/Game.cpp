/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */



#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "AIPlayer.h"
#include "RemotePlayerSender.h"


using namespace std;

Game::Game(RegularGameLogic *gameLogic, int choose, Display *consoleDisplay) {
    const char *filename = "cconfig.txt";
    int indexPlayer;
    bool secondPlayerJoined;
    this->blackTurn = true;
    this->gameLogic = gameLogic;
    this->display = consoleDisplay;
    if (choose == 1) {
        this->bHP = new HumanPlayer(Board::Black);
        this->wHP = new HumanPlayer(Board::White);
    } else if (choose == 2) {
        this->bHP = new HumanPlayer(Board::Black);
        this->wHP = new AIPlayer(Board::White);
    } else if (choose == 3) {
        try {
            //create a new player that connect to the server
            this->bHP = new RemotePlayerSender(filename);
            //connect to server
            this->bHP->connectToServer(display);
            // get from the server if the player is Black or White 1 for X , 2 for O.
            indexPlayer = this->bHP->getMoveFromServer();
            secondPlayerJoined = false;
        } catch (int e) {
            display->printString("Error reading message!. Server has been probably shutdown, closing the game");
            delete (this->gameLogic);
            delete (this->bHP);
            exit(1);
            }
        }
        if (indexPlayer == 1) {
            this->display->connectedToServer();
            this->display->waitingForOppToConnect();
            this->bHP->setType(Board::Black);
            while (!secondPlayerJoined) {
                try {
                    if (this->bHP->getMoveFromServer() == 3)
                        secondPlayerJoined = true;
                } catch (int e) {
                    display->printString("Error reading message!. Server has been probably shutdown, closing the game");
                    delete (this->gameLogic);
                    delete (this->bHP);
                    exit(1);
                }
            }
            this->wHP = new RemotePlayerReceiver(filename);
            //this->wHP->connectToServer();
            this->wHP->setType(Board::White);
            this->wHP->setClientSocket(this->bHP->getClientSocket());
        } else if (indexPlayer == 2) {
            this->display->connectedToServer();
            this->wHP = this->bHP;
            this->wHP->setType(Board::White);
            this->bHP = new RemotePlayerReceiver(filename);
            this->bHP->setType(Board::Black);
            //this->bHP->connectToServer();
            this->bHP->setClientSocket(this->wHP->getClientSocket());
        }

}

void Game::run() {
    bool noMoreActionsB = false;
    bool noMoreActionW = false;
    try {
        while (!this->gameLogic->checkAndAnnounceFinish(noMoreActionsB, noMoreActionW, display)) {
            Pair userInput;
            int moves = 0;
            Pair pArr[this->gameLogic->getBoardSize() * this->gameLogic->getBoardSize() + 1];
            display->currentBoard();
            display->printBoard(this->gameLogic->getBoard());
            if (this->blackTurn) {
                if (this->gameLogic->checkAndAnnounceFinish(noMoreActionsB, noMoreActionW, display)) {
                    this->bHP->finishGame();
                    return;
                }
                this->gameLogic->possibleMoves(pArr, moves, bHP->getType());
                if (moves == 0) {
                    this->bHP->noMove(this->display);
                    noMoreActionsB = true;
                } else {
                    do {
                        userInput = bHP->getMove(pArr, moves, this->gameLogic, Board::White, display);
                    } while (!this->gameLogic->checkInput(userInput, pArr, moves, display));
                    this->bHP->update(userInput.getRow(), userInput.getCol());
                    this->gameLogic->flipCell(userInput, Board::White, Board::Black);
                    // updating the server after the move according to the type
                    display->xPlayed();
                    display->printPair(Pair(userInput.getRow() - 1, userInput.getCol() - 1));
                    display->newLine();
                    noMoreActionsB = false;
                }
                this->blackTurn = false;
            } else {
                if (this->gameLogic->checkAndAnnounceFinish(noMoreActionsB, noMoreActionW, display)) {
                    this->wHP->finishGame();
                    return;
                }
                this->gameLogic->possibleMoves(pArr, moves, wHP->getType());
                if (moves == 0) {
                    this->wHP->noMove(this->display);
                    noMoreActionW = true;
                } else {
                    do {
                        userInput = wHP->getMove(pArr, moves, this->gameLogic, Board::Black, display);
                    } while (!this->gameLogic->checkInput(userInput, pArr, moves, display));
                    // updating the server after the move according to the type
                    this->gameLogic->flipCell(userInput, Board::Black, Board::White);
                    this->wHP->update(userInput.getRow(), userInput.getCol());
                    display->oPlayed();
                    display->printPair(Pair(userInput.getRow() - 1, userInput.getCol() - 1));
                    display->newLine();
                    noMoreActionW = false;
                }
                this->blackTurn = true;
            }
        }
    } catch (int e) {
        display->printString("Error reading message!. Server has been probably shutdown, closing the game");
        delete (this->gameLogic);
        delete (this->bHP);
        delete (this->wHP);
        exit(1);
    }
    this->bHP->finishGame();
    
}

Game::~Game() {
    delete (this->gameLogic);
    delete (this->bHP);
    delete (this->wHP);
}