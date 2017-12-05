//
// Created by raz on 12/5/17.
//

#ifndef EX4_REMOTEPLAYER_H
#define EX4_REMOTEPLAYER_H




#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

/*
 * This class features a remote player class.
 */
class RemotePlayer: public Player {
public:
    /**
     * Constructor for the human player.
     */
    RemotePlayer(Board::Status);
    /**
    * This method asks the user to pick he's selected move.
    * @param positions possible moves.
    * @param moves number of positions.
    * @param gl game logic.
    * @param opponentStat color of the opponent.
    * @param display display.
    * @return user's decided move.
    */
    const Pair getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, Display* display);
};


#endif //EX4_REMOTEPLAYER_H
