/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX4_REMOTEPLAYERRECEIVER_H
#define EX4_REMOTEPLAYERRECEIVER_H


#include "Player.h"

class RemotePlayerReceiver : public Player {
public:
    /**
     * Constructor by a file name.
     * @param filename
     */
    RemotePlayerReceiver(const char *filename);

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
     * this method connects the player to the server
     */
    void connectToServer(Display* display);

    /**
     * this method get move from server
     * @return the number that we got from the server
     */
    int getMoveFromServer(Display* display);

    /**
     * this method appears when the player has no move
     * @param display a given display og the game
     */
    void noMove(Display *display);
    /**
     * Destructor for player.
     */
    ~RemotePlayerReceiver();
};


#endif //EX4_REMOTEPLAYERRECEIVER_H
