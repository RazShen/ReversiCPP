/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX2_AIPLAYER_H
#define EX2_AIPLAYER_H

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

/**
 * This class features an AI player (a player with decisions made by AI).
 */
class AIPlayer: public Player {
public:
    /**
     * This is a constructor for an AI player.
     */
    AIPlayer(Board::Status);

    /**
     * This method returns a move from the player (in this case the AI player calculates the move itself).
     * @param positions possible positions.
     * @param moves number of positions.
     * @param gl game logic.
     * @param opponentStat opponent color.
     * @param display the display.
     * @return selected move.
     */
    const Pair getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, ConsoleDisplay* display);
};


#endif //EX2_AIPLAYER_H
