/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX4_REMOTEPLAYERSENDER_H
#define EX4_REMOTEPLAYERSENDER_H


#include "Board.h"
#include "RemotePlayerReceiver.h"

class RemotePlayerSender : public Player {
public:
    /**
     * Constructor by a file name
     *
     * @param filename
     */
    RemotePlayerSender(const char *filename);

    /**
    * This method asks the user to pick he's selected move.
    * @param positions possible moves.
    * @param moves number of positions.
    * @param gl game logic.
    * @param opponentStat color of the opponent.
    * @param display display.
    * @return user's decided move.
    */
    const Pair getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display);

    /**
     * this method updates the valid move to the server
     * @param arg1 a first given num of a pair
     * @param arg2 a sec given num of a pair
     */
    void update(int arg1, int arg2);

    /**
     * this method updates the server that the game finished
     */
    void finishGame();

    /**
 * this method connects the player to the server
 */
    void connectToServer(Display *display);

    /**
     * this method get move from server
     * @return the number that we got from the server
     */
    int getMoveFromServer();

    /**
     * this method appears when the player has no move
     * @param display a given display of the game
     */
    void noMove(Display *display);

    /**
     * Destructor for player.
     */
    ~RemotePlayerSender();
   /**
    * get the player menu for the user
    * @param display the given display of the game
    */
    void playerMenu(Display* display);
    /**
     * parse operation to string command
     * @param operation a given opration
     * @param name og the game
     * @return the sting that represent the full command
     */
    string ParseOperation(int operation, string name);
/**
 * this function write to server a command
 * @param command a given command
 */
    void writeToServer(string command);
    /**
     * this function read from server a command
     * @return a given command
     */
    string readFromServer();
};

#endif //EX4_REMOTEPLAYERSENDER_H
