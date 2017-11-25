/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


/*
 * Game.h
 *  This class features a specific game for 2 users.
 *  Created on: Nov 2, 2017
 *      Author: Raz Shenkman
 */

#ifndef EX2_GAME_H
#define EX2_GAME_H


#include "HumanPlayer.h"
#include "GameLogic.h"
#include "Board.h"
#include "ConsoleDisplay.h"
#include "RegularGameLogic.h"
#include <string>

class Game {
public:
    /**
     * Constructor for HumanPlayersOnComputer class.
     * @param gameLogic inputted pointer to game logic.
     */
    Game(RegularGameLogic *gameLogic, int choose, ConsoleDisplay* consoleDisplay);

    /**
     * This method runs the game.
     */
    void run();

    /**
     * Destructor for HumanPlayersOnComputer game.
     */
    ~Game();

private:
    // Human players.
    GameLogic *gameLogic;
    bool blackTurn;
    Player* bHP;
    Player* wHP;
    ConsoleDisplay* display;
};


#endif //EX2_GAME_H