//ID: 311130777
//Name: Raz Shenkman
/*
 * HumanPlayer.h
 *  This struct features a human player.
 *  Created on: Nov 2, 2017
 *  Author: Raz Shenkman
 */

#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"


class HumanPlayer: public Player {
public:
    HumanPlayer(Board::Status);
    const Pair getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, ConsoleDisplay* display);
};


#endif //EX2_HUMANPLAYER_H