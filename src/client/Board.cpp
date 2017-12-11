/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "Board.h"
#include <iostream>
#include <cstdlib>


using namespace std;


Board::Board(int &size) {
    this->size = size;
    try {
        this->cellArray = new Status *[this->size];
        for (int i = 0; i < this->size; i++) {
            this->cellArray[i] = new Status[this->size];
        }
    } catch (std::bad_alloc &exc) {
        cout << "Can't allocate memory for the board" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->cellArray[i][j] = Empty;
        }
    }
    this->cellArray[this->size / 2 - 1][this->size / 2 - 1] = White;
    this->cellArray[this->size / 2][this->size / 2] = White;
    this->cellArray[this->size / 2 - 1][this->size / 2] = Black;
    this->cellArray[this->size / 2][this->size / 2 - 1] = Black;

}

Board::Board(const Board &b) {
    this->size = b.size;
    try {
        this->cellArray = new Status *[this->size];
        for (int i = 0; i < this->size; i++) {
            this->cellArray[i] = new Status[this->size];
        }
    } catch (std::bad_alloc &exc) {
        cout << "Can't allocate memory for the board" << endl;
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->cellArray[i][j] = b.getCellStatus(Pair(i, j));
        }
    }
}

Board::Status Board::getCellStatus(const Pair &p) const {
    if (p.getRow() >= 0 && p.getRow() < this->getSize() && p.getCol() >= 0 && p.getCol() < this->getSize()) {
        return this->cellArray[p.getRow()][p.getCol()];
    }
}

void Board::changeStatus(const Pair &p, Status s) {
    if (p.getRow() >= 0 && p.getRow() < this->getSize() && p.getCol() >= 0 && p.getCol() < this->getSize()) {
        this->cellArray[p.getRow()][p.getCol()] = s;
    }
}

bool Board::isBoardFull() const {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->cellArray[i][j] == Board::Empty) {
                return false;
            }
        }
    }
    return true;
}

Board::~Board() {
    for (int i = 0; i < this->size; i++) {
        delete[] this->cellArray[i];
    }
    delete[] this->cellArray;
}

int Board::getSize() const {
    return this->size;
}

Board::Status **Board::getMatrix() {
    return cellArray;
}

