//ID: 311130777
//Name: Raz Shenkman
/*
 * HumanPlayer.cpp
 *  This struct features a human player.
 *  Created on: Nov 2, 2017
 *      Author: Raz Shenkman
 */

#include <iostream>
#include <limits>
#include "HumanPlayer.h"
using namespace std;

HumanPlayer::HumanPlayer(Board::Status stat): Player(stat) {

}


const Pair HumanPlayer::getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, Display* display) {
    int xUser, yUser;
    display->itsYourMove(this->getType());
    display->possibleMoves(positions, moves);
    display->getInput();
    cin >> xUser >> yUser;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // illegal value in purpose
        xUser = -5;
        yUser = -5;
    }
    Pair inputUser = Pair(xUser, yUser);
    return inputUser;
}