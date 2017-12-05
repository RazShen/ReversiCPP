//
// Created by raz on 12/5/17.
//

#ifndef EX4_REMOTEGAME_H
#define EX4_REMOTEGAME_H

#include "HumanPlayer.h"
#include "GameLogic.h"
#include "Board.h"
#include "ConsoleDisplay.h"
#include "RegularGameLogic.h"
#include "client/RemotePlayerC.h"
#include <string>

class RemoteGame {
public:
    /**
     * Constructor for HumanPlayersOnComputer class.
     * @param gameLogic inputted pointer to game logic.
     */
    RemoteGame(RegularGameLogic *gameLogic, Display *consoleDisplay);

    /**
     * This method runs the game.
     */
    void run();

    /**
     * Destructor for HumanPlayersOnComputer game.
     */
    ~RemoteGame();

private:
    GameLogic *gameLogic;
    bool blackTurn;
    RemotePlayerC *bHP;
    RemotePlayerC *wHP;
    Display *display;
};


#endif //EX4_REMOTEGAME_H
