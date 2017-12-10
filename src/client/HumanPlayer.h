/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_HUMANPLAYER_H
#define EX3WITHTESTS_HUMANPLAYER_H

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"

/*
 * This class features a human player class.
 */
class HumanPlayer : public Player {
public:
    /**
     * Constructor for the human player.
     */
    HumanPlayer(Board::Status);

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
    * this method appears when the player has no move
     * @param display a given display of the game
     */
    void noMove(Display *display);
};


#endif //EX3WITHTESTS_HUMANPLAYER_H