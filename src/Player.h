//
// Created by raz on 11/18/17.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "Pair.h"
#include "Board.h"
#include "GameLogic.h"

class Player {
public:

    /**
     * Constructor for the player (from status)
     * @param stat: wanted status.
     */
    Player(Board::Status status);

    Player();

    /**
     * This method return the wanted move the player decided.
     * @param b board.
     * @param positions possible positions
     * @param moves number of positions
     * @return wanted move
     */
    virtual const Pair getMove(Pair positions[], int moves,GameLogic* gl, Board::Status opponentStat, ConsoleDisplay* display) = 0;

    /**
     * This method returns the player's type.
     * @return
     */
    Board::Status getType() const;
private:
    Board::Status type;

};


#endif //EX2_PLAYER_H
