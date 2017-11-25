//
// Created by raz on 11/18/17.
//

#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

class AIPlayer: public Player {
public:
    AIPlayer(Board::Status);
    const Pair getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, Display* display);
};


#endif //EX2_AIPLAYER_H
