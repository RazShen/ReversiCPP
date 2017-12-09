/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */



#include <iostream>
#include "Game.h"
#include "AIPlayer.h"
#include "client/RemotePlayerSender.h"


using namespace std;

Game::Game(RegularGameLogic *gameLogic, int choose, Display *consoleDisplay) {
    const char* filename = "server/sconfig.txt";
    this->blackTurn = true;
    this->gameLogic = gameLogic;
    this->display = consoleDisplay;
    if (choose == 1) {
        this->bHP = new HumanPlayer(Board::Black);
        this->wHP = new HumanPlayer(Board::White);
        secondPlayerJoined = true;
    } else if (choose == 2) {
        this->bHP = new HumanPlayer(Board::Black);
        this->wHP = new AIPlayer(Board::White);
        secondPlayerJoined = true;
    } else if (choose == 3) {
        //create a new player that connect to the server
        this->bHP = new RemotePlayerSender(filename);
        //connect to server
        this->bHP->connectToServer();
        // get from the server if the player is Black or White 1 for X , 2 for O.
        int indexPlayer = this->bHP->getMoveFromServer();
        bool secondPlayerJoined = false;
        if (indexPlayer == 1) {
            this->display->connectedToServer();
            this->display->waitingForOppToConnect();
            this->bHP->setType(Board::Black);
            while (!secondPlayerJoined) {
                if(this->bHP->getMoveFromServer() == 3)
                    secondPlayerJoined = true;
            }
            this->wHP = new RemotePlayerReceiver(filename);
            this->wHP->connectToServer();
            this->wHP->setType(Board::White);
            this->wHP->setClientSocket(this->bHP->getClientSocket());
        } else if (indexPlayer == 2) {
            this->display->connectedToServer();
            this->wHP = this->bHP;
            this->wHP->setType(Board::White);
            this->bHP = new RemotePlayerReceiver(filename);
            this->bHP->setType(Board::Black);
            bool secondPlayerJoined = true;
            this->bHP->connectToServer();
            this->bHP->setClientSocket(this->wHP->getClientSocket());
        }
    }
}



void Game::run() {
    bool noMoreActionsB = false;
    bool noMoreActionW = false;
    while (!this->gameLogic->checkAndAnnounceFinish(noMoreActionsB, noMoreActionW, display)) {
        Pair userInput;
        int moves = 0;
        Pair pArr[this->gameLogic->getBoardSize() * this->gameLogic->getBoardSize() + 1];
        display->currentBoard();
        display->printBoard(this->gameLogic->getBoard());
        if (this->blackTurn) {
            this->gameLogic->possibleMoves(pArr, moves, bHP->getType());
            if (moves == 0) {
                this->bHP->noMove(this->display);
//                string anyKey;
//                display->noPossibleMoves();
//                std::getline(cin, anyKey);
//                display->newLine();
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
                return;
            }
            this->gameLogic->possibleMoves(pArr, moves, wHP->getType());
            if (moves == 0) {
                this->wHP->noMove(this->display);
//                string anyKey;
//                display->noPossibleMoves();
//                std::getline(cin, anyKey);
//                display->newLine();
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
}

Game::~Game() {
    delete (this->gameLogic);
    delete (this->bHP);
    delete (this->wHP);
}