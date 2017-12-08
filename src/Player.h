/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_PLAYER_H
#define EX3WITHTESTS_PLAYER_H


#include "Pair.h"
#include "Board.h"
#include "GameLogic.h"

/**
 * This class features a general player.
 */
class Player {
public:

    /**
     * Constructor for the player (from status)
     * @param stat: wanted status.
     */
    Player(Board::Status status);

    /**
     * Empty constructor for the player.
     */
    Player();
    Player(const char* filename);
    /**
     * This method return the wanted move the player decided.
     * @param b board.
     * @param positions possible positions
     * @param moves number of positions
     * @return wanted move
     */
    virtual const Pair
    getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display) = 0;
    Player(const char *serverIP, int serverPort);
    virtual void connectToServer();
    virtual void update(int arg1, int arg2);
    virtual int getMoveFromServer();
    virtual void noMove(Display* display);

    /**
     * This method returns the player's type.
     * @return
     */
    Board::Status getType() const;
    void setType(Board::Status stat);

protected:
    Board::Status type;
    const char *serverIP;
    int serverPort;

};


#endif //EX3WITHTESTS_PLAYER_H
