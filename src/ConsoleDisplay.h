/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_CONSOLEDISPLAY_H
#define EX3WITHTESTS_CONSOLEDISPLAY_H


#include "Board.h"
#include "Display.h"

/**
 * This class is used to print on the console.
 */
class ConsoleDisplay : public Display {
public:
    /**
     * Constructor for the console display.
     */
    ConsoleDisplay();
    /**
    * print board
    * @param board given board
     */
    void printBoard(Board* board);
    /**
     * this method prints possible Moves
     * @param given positions
     * @param moves number of moves
     */
    void possibleMoves(Pair positions[], int moves);
    /**
     * this method prints no valid move option
     */
    void noValidMove();
    /**
     * this method prints no valid option
     */
    void noValidOption();
    /**
     * this method prints a current board.
     */
    void currentBoard();
    /**
     * this method prints it's Your Move for a player.
     */
    void itsYourMove(Board::Status);
    /**
     * this method prints x played.
     */
    void xPlayed();
    /**
     * this method prints o played.
     */
    void oPlayed();
    /**
     * this method prints the welcome menu.
     */
    void welcome();
    /**
     * this method prints and ask an input from the player.
     */
    void getInput();

    /**
     * this method prints new line.
     */
    void newLine();
    /**
     * this method prints a pair.
     * @param p a given pair
     */
    void printPair(Pair p);
    /**
     * this method prints game options.
     */
    void chooseGameOptions();
    /**
     * this method prints any Key To Exit Massage.
     */
    void anyKeyToExitMassage();
    /**
     * this method prints black win.
     */
    void declareBlackWin();
    /**
     * this method prints white win.
     */
    void declareWhiteWIn();
    /**
     * this method prints it's a draw.
     */
    void declareDraw();
    /**
     * this method prints that the board it full.
     */
    void fullBoard();
    /**
     * this method prints that there is no more moves for both player.
     */
    void noMoreMovesForAll();
    /**
     * Waiting for the opponent move.
     */
    void waitForMove();

    /**
     * this method prints that a player has no possible moves
     * @param stat a given player
     */
    void noPossiblePlayerMove(Board::Status stat);
    /**
     * this method prints that the player is waiting for opponent to connect
     */
    void waitingForOppToConnect();
    /**
     * this method prints connected to server
     */
    void connectedToServer();
    /**
     * this method prints the waiting for opponent player to play
     */
    void waitingForOppToPlay();
    /**
     * this methos prints press any key to continue
     */
    void pressAnyKey();
};

#endif //EX3WITHTESTS_CONSOLEDISPLAY_H
