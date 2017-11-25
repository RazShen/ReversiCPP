/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


/*
 * Game.cpp
 *  This class features a specific game for 2 users.
 *  Created on: Nov 2, 2017
 *      Author: Raz Shenkman
 */

#include <iostream>
#include "Game.h"
#include "AIPlayer.h"

using namespace std;

Game::Game(RegularGameLogic *gameLogic, int choose, ConsoleDisplay* consoleDisplay) {
    this->blackTurn = true;
    this->gameLogic = gameLogic;
    display = consoleDisplay;
    this->bHP = new HumanPlayer(Board::Black);
    if(choose == 1) {
        this->wHP = new HumanPlayer(Board::White);
    } else if(choose == 2){
        this->wHP = new AIPlayer(Board::White);
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
                string anyKey;
                display->noPossibleMoves();
                std::getline(cin, anyKey);
                display->newLine();
                noMoreActionsB = true;
            } else {
                do {
                    userInput = bHP->getMove(pArr, moves, this->gameLogic, Board::White, display);
                } while (!this->gameLogic->checkInput(userInput, pArr, moves, display));
                this->gameLogic->flipCell(userInput, Board::White, Board::Black);
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
                string anyKey;
                display->noPossibleMoves();
                std::getline(cin, anyKey);
                display->newLine();
                noMoreActionW = true;
            } else {
                do {
                    userInput = wHP->getMove(pArr, moves, this->gameLogic, Board::White, display);
                } while (!this->gameLogic->checkInput(userInput, pArr, moves, display));
                this->gameLogic->flipCell(userInput, Board::Black, Board::White);
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
    delete(this->bHP);
    delete(this->wHP);
}