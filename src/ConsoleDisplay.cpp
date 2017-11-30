/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#include <iostream>
#include "ConsoleDisplay.h"

ConsoleDisplay::ConsoleDisplay() {}

void ConsoleDisplay::printBoard(Board *board) {
    int size = board->getSize();
    int boardCoordinates[size];
    for (int i = 0; i < size; i++) {
        boardCoordinates[i] = i + 1;
    }
    string dottedLine = "----------------------------------";
    for (int i = 0; i < size; i++) {
        cout << " | " << boardCoordinates[i];
    }
    cout << " | " << endl;
    cout << dottedLine << endl;
    for (int i = 0; i < size; i++) {
        cout << boardCoordinates[i] << "|";
        for (int j = 0; j < size; j++) {
            Board::Status stat = board->getCellStatus(Pair(i, j));
            switch (stat) {
                case Board::Empty:
                    cout << "   |";
                    break;
                case Board::White:
                    cout << " O |";
                    break;
                case Board::Black:
                    cout << " X |";
                    break;
            }
        }
        cout << "" << endl;
        cout << dottedLine << endl;
    }
}

void ConsoleDisplay::noValidMove() {
    cout << "Bad arguments, please type only a valid move" << endl;
}

void ConsoleDisplay::currentBoard() {
    cout << "Current board:" << endl << endl;
}

void ConsoleDisplay::itsYourMove(Board::Status player) {
    if (player == Board::White) {
        cout << "O: It's your move." << endl;
    }
    if (player == Board::Black) {
        cout << "X: It's your move." << endl;
    }
}

void ConsoleDisplay::possibleMoves(Pair *positions, int moves) {
    cout << "Your possible moves: ";
    for (int i = 0; i < moves; i++) {
        if (i != 0) {
            cout << ",";
        }
        printPair(positions[i]);
    }
    cout << "" << endl << endl;
}

void ConsoleDisplay::xPlayed() {
    cout << "X played ";

}

void ConsoleDisplay::getInput() {
    cout << "Please enter your move row (space) col: ";
}

void ConsoleDisplay::noPossibleMoves() {
    cout << "No possible moves. Play passes back to other player. Press any key to continue." << endl;
}

void ConsoleDisplay::newLine() {
    cout << "" << endl;
}

void ConsoleDisplay::oPlayed() {
    cout << "O played ";
}

void ConsoleDisplay::printPair(Pair p) {
    cout << "(" << p.getRow() + 1 << "," << p.getCol() + 1 << ")";
}

void ConsoleDisplay::welcome() {
    cout << "Welcome to reversi game, choose your game mode" << endl;
}

void ConsoleDisplay::chooseGameOptions() {
    cout << "Press 1 to play against a human player " << endl;
    cout << "Press 2 to play against a computer player" << endl;
}

void ConsoleDisplay::noValidOption() {
    cout << "No valid option" << endl;
}

void ConsoleDisplay::anyKeyToExitMassage() {
    cout << "Game Over" << endl;
}

void ConsoleDisplay::fullBoard() {
    cout << "The board is full" << endl;
}

void ConsoleDisplay::declareBlackWin() {
    cout << "Black player wins" << endl;
}

void ConsoleDisplay::declareWhiteWIn() {
    cout << "White player wins" << endl;
}

void ConsoleDisplay::declareDraw() {
    cout << "It's a draw" << endl;
}

void ConsoleDisplay::noMoreMovesForAll() {
    cout << "No more moves available for both players: " << endl;
}