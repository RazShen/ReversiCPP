/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#include <iostream>
#include "ConsoleDisplay.h"

ConsoleDisplay::ConsoleDisplay() {}

void ConsoleDisplay::printBoard(Board *board) {
    int size = board->getSize();
    Board::Status **cells = board->getMatrix();
    int i, j;
    char symbol = ' ';
    cout << " |";
    for (i = 0; i < size; i++) {
        cout << " " << i + 1 << " |";
    }
    cout << endl;
    cout << "--";
    for (i = 0; i < size; i++) {
        cout << "----";
    }
    cout << endl;
    for (i = 0; i < size; i++) {
        cout << i + 1 << "|";

        for (j = 0; j < size; j++) {
            if (cells[i][j] == Board::Empty) {
                symbol = ' ';
            }
            if (cells[i][j] == Board::White) {
                symbol = 'O';
            }
            if (cells[i][j] == Board::Black) {
                symbol = 'X';
            }
            cout << " " << symbol << " |";
        }
        cout << endl;
        cout << "--";
        for (j = 0; j < size; j++) {
            cout << "----";
        }
        cout << endl;
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
    cout << "Welcome to reversi game" << endl << endl << "choose your opponent type" << endl;
}

void ConsoleDisplay::chooseGameOptions() {
    cout << "1. A human local player" << endl;
    cout << "2. An AI player" << endl;
    cout << "3. A remote player" << endl;
}

void ConsoleDisplay::noValidOption() {
    cout << "No valid option" << endl;
}

void ConsoleDisplay::exitMassage() {
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

void ConsoleDisplay::waitForMove() {
    cout << "Waiting for other player's move..." << endl;
}

void ConsoleDisplay::noPossiblePlayerMove(Board::Status stat) {
    cout << "No possible moves for ";
    if (stat == Board::Black) {
        cout << "X" << endl;
    } else {
        cout << "O" << endl;
    }
    cout << "Play passes back to other player" << endl;

}

void ConsoleDisplay::waitingForOppToConnect() {
    cout << "Waiting for other player to join..." << endl;
}

void ConsoleDisplay::connectedToServer() {
    cout << "Connected to server" << endl;
}

void ConsoleDisplay::waitingForOppToPlay() {
    cout << "Waiting for other player's move..." << endl;
}

void ConsoleDisplay::pressAnyKey() {
    cout << "Press any key to continue..." << endl;
}

void ConsoleDisplay::printClientMenu() {
    cout << "please choose operation number and a name of the game (for 1,3) " << endl;
    cout << "1 for starting a new game." << endl;
    cout << "2 for viewing the list of waiting games." << endl;
    cout << "3 for joining a waiting game." << endl;
}

void ConsoleDisplay::notAvailableGame() {
    cout << "Error! not a valid game name." << endl;
}

void ConsoleDisplay::gameAlreadyExist() {
    cout << "Error! The game already exists." << endl;
}

void ConsoleDisplay::gameNotOption() {
    cout << "Invalid option! Please choose again." << endl;
}

void ConsoleDisplay::EnterNameOfGame() {
    cout << "please enter the name of your game" << endl;
}
void ConsoleDisplay::printString(string stringToPrint) {
    cout << stringToPrint << endl;
}

void ConsoleDisplay::printAvailableGames(string availableGamesNames) {
    printString(availableGamesNames);
}

