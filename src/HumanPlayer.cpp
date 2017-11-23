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


const Pair HumanPlayer::getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, ConsoleDisplay* display) {
    int xUser, yUser;
    display->itsYourMove(this->getType());
    display->possibleMoves(positions, moves);
    display->getInput();
//    if(this->getType() == Board::White) {
//        cout << "O: It's your move." << endl;
//    }
//    if(this->getType() == Board::Black) {
//        cout << "X: It's your move." << endl;
//    }
//    cout << "Your possible moves: ";
//    for (int i = 0; i < moves; i++) {
//        if (i != 0) {
//            cout << ",";
//        }
//        positions[i].print();
//    }
//    cout << "" << endl << endl;
//    cout << "Please enter your move row (space) col: ";
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