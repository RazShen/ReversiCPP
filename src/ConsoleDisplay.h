//
// Created by tomer on 11/21/17.
//

#ifndef EX2_CONSOLEDISPLAY_H
#define EX2_CONSOLEDISPLAY_H


#include "Board.h"
#include "Display.h"

class ConsoleDisplay : public Display {
public:
    ConsoleDisplay();
    void printBoard(Board* board);
    void possibleMoves(Pair positions[], int moves);
    void noValidMove();
    void noValidOption();
    void currentBoard();
    void itsYourMove(Board::Status);
    void xPlayed();
    void oPlayed();
    void welcome();
    void getInput();
    void noPossibleMoves();
    void newLine();
    void printPair(Pair p);
    void chooseGameOptions();
    void anyKeyToExitMassage();
    void declareBlackWin();
    void declareWhiteWIn();
    void declareDraw();
    void fullBoard();
    void noMoreMovesForAll();

};

#endif //EX2_CONSOLEDISPLAY_H
