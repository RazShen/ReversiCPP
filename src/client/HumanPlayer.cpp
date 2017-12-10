/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <iostream>
#include <limits>
#include <cstdlib>
#include "HumanPlayer.h"

using namespace std;

HumanPlayer::HumanPlayer(Board::Status stat) : Player(stat) {

}

const Pair
HumanPlayer::getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display) {
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

void HumanPlayer::noMove(Display *display) {
    string anyKey;
    display->noPossiblePlayerMove(this->getType());
    getline(cin, anyKey);
    do
    {
        cout << '\n' << "Press a key to continue...";
    } while (cin.get() != '\n');
    display->newLine();
}
