//
// Created by raz on 12/5/17.
//

#include "RemotePlayer.h"

#include <iostream>
#include <limits>
#include "HumanPlayer.h"

using namespace std;

RemotePlayer::RemotePlayer(Board::Status stat) : Player(stat) {

}

const Pair
RemotePlayer::getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display) {
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