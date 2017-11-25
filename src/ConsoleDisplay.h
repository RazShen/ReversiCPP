/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX2_CONSOLEDISPLAY_H
#define EX2_CONSOLEDISPLAY_H


#include "Board.h"

class ConsoleDisplay {
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
