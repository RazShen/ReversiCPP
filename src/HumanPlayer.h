/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
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

    /**
     * This method returns a move from the player (in this case the human player decides the move himself).
     * @param positions possible positions.
     * @param moves number of positions.
     * @param gl game logic.
     * @param opponentStat opponent color.
     * @param display the display.
     * @return selected move.
     */
    const Pair getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, ConsoleDisplay* display);
};


#endif //EX2_HUMANPLAYER_H