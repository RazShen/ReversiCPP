//ID: 311130777
//Name: Raz Shenkman
/*
 * main.cpp
 *  The main function of the program.
 *  Created on: Nov 3, 2017
 *  Author: Raz Shenkman
 */

#include <iostream>
#include <limits>
#include "Game.h"
using namespace std;
/**
 * This main function creates a new game with new game logic and runs the game
 * @return 0
 */
int main() {
    int boardSize = 8;
    int input = 0;
    bool isNotValidInput;
    Display* display = new ConsoleDisplay();
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
    } while(isNotValidInput);
    Game game = Game(new RegularGameLogic(boardSize, GameLogic::Regular), input, display);
    game.run();
    string anyKey;
    display->anyKeyToExitMassage();
    getline(cin, anyKey);
    delete(display);
    return 0;
}