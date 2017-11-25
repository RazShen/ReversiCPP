//
// Created by tomer on 11/25/17.
//

#ifndef EX3WITHTESTS_DISPLAY_H
#define EX3WITHTESTS_DISPLAY_H

#include "Board.h"

class Display {
public:

    virtual void printBoard(Board* board) = 0;
    virtual void possibleMoves(Pair positions[], int moves) = 0;
    virtual void noValidMove() = 0;
    virtual void noValidOption() = 0;
    virtual void currentBoard() = 0;
    virtual void itsYourMove(Board::Status) = 0;
    virtual void xPlayed() = 0;
    virtual void oPlayed() = 0;
    virtual void welcome() = 0;
    virtual void getInput() = 0;
    virtual void noPossibleMoves() = 0;
    virtual void newLine() = 0;
    virtual void printPair(Pair p) = 0;
    virtual void chooseGameOptions() = 0;
    virtual void anyKeyToExitMassage() = 0;
    virtual void declareBlackWin() = 0;
    virtual void declareWhiteWIn() = 0;
    virtual void declareDraw() = 0;
    virtual void fullBoard() = 0;
    virtual void noMoreMovesForAll() = 0;

};
#endif //EX3WITHTESTS_DISPLAY_H
