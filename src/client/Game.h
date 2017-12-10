/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */



#ifndef EX3WITHTESTS_GAME_H
#define EX3WITHTESTS_GAME_H


#include "HumanPlayer.h"
#include "GameLogic.h"
#include "Board.h"
#include "ConsoleDisplay.h"
#include "RegularGameLogic.h"
#include "RemotePlayerReceiver.h"
#include <string>

/**
 * This class features a game class, it runs the game.
 */
class Game {
public:
    /**
     * Constructor for HumanPlayersOnComputer class.
     * @param gameLogic inputted pointer to game logic.
     */
    Game(RegularGameLogic *gameLogic, int choose, Display *consoleDisplay);

    /**
     * This method runs the game.
     */
    void run();

    /**
     * Destructor for HumanPlayersOnComputer game.
     */
    ~Game();

private:
    GameLogic *gameLogic;
    bool blackTurn;
    Player *bHP;
    Player *wHP;
    Display *display;
};


#endif //EX3WITHTESTS_GAME_H