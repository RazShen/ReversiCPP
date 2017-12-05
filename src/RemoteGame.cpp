////
//// Created by raz on 12/5/17.
////
//
//#include <iostream>
//#include "Game.h"
//#include "RemoteGame.h"
//#include "client/RemotePlayerSender.h"
//
//
//using namespace std;
//
//RemoteGame::RemoteGame(RegularGameLogic *gameLogic, Display *consoleDisplay) {
//    this->blackTurn = true;
//    this->gameLogic = gameLogic;
//    this->display = consoleDisplay;
//    this->localP = new RemotePlayerSender(Board::Empty);
//    this->remoteP = new RemotePlayerReceiver(Board::Empty);
//}
//
//void RemoteGame::run() {
//    this->localP->connectToServer();
//
//    bool noMoreActionsB = false;
//    bool noMoreActionW = false;
//    while (!this->gameLogic->checkAndAnnounceFinish(noMoreActionsB, noMoreActionW, display)) {
//        Pair userInput;
//        int moves = 0;
//        Pair pArr[this->gameLogic->getBoardSize() * this->gameLogic->getBoardSize() + 1];
//        display->currentBoard();
//        display->printBoard(this->gameLogic->getBoard());
//        if (this->blackTurn) {
//            this->gameLogic->possibleMoves(pArr, moves, localP->getType());
//            if (moves == 0) {
//                string anyKey;
//                display->noPossibleMoves();
//                std::getline(cin, anyKey);
//                display->newLine();
//                noMoreActionsB = true;
//            } else {
//                do {
//                    userInput = localP->getMove(pArr, moves, this->gameLogic, Board::White, display);
//                } while (!this->gameLogic->checkInput(userInput, pArr, moves, display));
//                //send to server
//                this->gameLogic->flipCell(userInput, Board::White, Board::Black);
//                display->xPlayed();
//                display->printPair(Pair(userInput.getRow() - 1, userInput.getCol() - 1));
//                display->newLine();
//                noMoreActionsB = false;
//            }
//            this->blackTurn = false;
//        } else {
//
//            if (this->gameLogic->checkAndAnnounceFinish(noMoreActionsB, noMoreActionW, display)) {
//                return;
//            }
//            this->gameLogic->possibleMoves(pArr, moves, remoteP->getType());
//            if (moves == 0) {
//                string anyKey;
//                display->noPossibleMoves();
//                std::getline(cin, anyKey);
//                display->newLine();
//                noMoreActionW = true;
//            } else {
//                do {
//                    userInput = remoteP->getMove(pArr, moves, this->gameLogic, Board::White, display);
//                } while (!this->gameLogic->checkInput(userInput, pArr, moves, display));
//                //send to server
//                this->gameLogic->flipCell(userInput, Board::Black, Board::White);
//                display->oPlayed();
//                display->printPair(Pair(userInput.getRow() - 1, userInput.getCol() - 1));
//                display->newLine();
//                noMoreActionW = false;
//            }
//            this->blackTurn = true;
//        }
//    }
//}
//
//RemoteGame::~RemoteGame() {
//    delete (this->gameLogic);
//    delete (this->localP);
//    delete (this->remoteP);
//}