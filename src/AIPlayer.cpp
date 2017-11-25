/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */



#include "AIPlayer.h"

using namespace std;

AIPlayer::AIPlayer(Board::Status stat) : Player(stat) {

}


const Pair
AIPlayer::getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, ConsoleDisplay *display) {
    int score = -(gl->getBoard()->getSize() * gl->getBoard()->getSize() + 1);
    int arrayOfMaxOpp[moves];
    // Scan all the moves to find the most valuable one
    for (int i = 0; i < moves; i++) {
        int numOpponentMoves = 0;
        // clone the game logic.
        GameLogic *newGL = gl->clone();
        newGL->flipCell(positions[i], opponentStat, this->getType());
        Pair opponentMoves[newGL->getBoardSize() * newGL->getBoardSize() + 1];
        newGL->possibleMoves(opponentMoves, numOpponentMoves, opponentStat);
        int maxScore = score;
        // scan all the opponent moves and select the least valuable one.
        for (int j = 0; j < numOpponentMoves; j++) {
            // clone the game logic.
            GameLogic *opponentGL = newGL->clone();
            opponentGL->flipCell(Pair(opponentMoves[j].getRow() + 1, opponentMoves[j].getCol() + 1), this->getType(),
                                 opponentStat);
            int curScore = opponentGL->getBlackScore();
            if (curScore > maxScore) {
                maxScore = curScore;
            }
            delete (opponentGL);
        }
        arrayOfMaxOpp[i] = maxScore;
        delete (newGL);

    }
    int curMin = arrayOfMaxOpp[0];
    int indexOfMin = 0;
    for (int p = 0; p < moves; p++) {
        if (arrayOfMaxOpp[p] <= curMin) {
            curMin = arrayOfMaxOpp[p];
            indexOfMin = p;
        }
    }
    return Pair(positions[indexOfMin].getRow() + 1, positions[indexOfMin].getCol() + 1);
}


