/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <iostream>
#include <limits>
#include "Game.h"

using namespace std;

/**
 * This main function creates a display, a menu to seleect the user's choice and a new game with new game logic and
 * runs the game.
 * @return 0
 */
int main() {
    int boardSize = 8;
    int input = 0;
    bool isNotValidInput;
    Display *display = new ConsoleDisplay();
    display->welcome();
    do {
        display->chooseGameOptions();
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (input != 1 && input != 2) {
            display->noValidOption();
            isNotValidInput = true;
        } else {
            isNotValidInput = false;
        }
    } while (isNotValidInput);
    Game game = Game(new RegularGameLogic(boardSize, GameLogic::Regular), input, display);
    game.run();
    display->anyKeyToExitMassage();
    delete (display);
    return 0;
}