/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#ifndef EX3WITHTESTS_AIPLAYER_H
#define EX3WITHTESTS_AIPLAYER_H

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

/**
 * This class features an AI player (whose decisions are calculated by AI).
 */
class AIPlayer : public Player {
public:
    /**
     * Constructor for the AI player.
     */
    AIPlayer(Board::Status);

    /**
     * This method picks the most valuable move for this player and the least valuable move for it's opponent.
     * @param positions possible moves.
     * @param moves number of positions.
     * @param gl game logic.
     * @param opponentStat color of the opponent.
     * @param display display.
     * @return most valuable move.
     */
    const Pair getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display);

    /**
     * this method appears when the player has no move
     * @param display a given display of the game
     */
    void noMove(Display *display);
};


#endif //EX3WITHTESTS_AIPLAYER_H
