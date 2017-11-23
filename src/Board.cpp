//ID: 311130777
//Name: Raz Shenkman
/*
 * Board.cpp
 *  This class features a game board.
 *  Created on: Nov 2, 2017
 *      Author: Raz Shenkman
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
    this->cellArray[3][3] = White;
    this->cellArray[4][4] = White;
    this->cellArray[3][4] = Black;
    this->cellArray[4][3] = Black;

}
Board::Board(const Board& b) {
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

//
//void Board::print() const {
//    int boardCoordinates[this->size];
//    for (int i = 0; i < this->size; i++) {
//        boardCoordinates[i] = i + 1;
//    }
//    string dottedLine = "----------------------------------";
//    for (int i = 0; i < this->size; i++) {
//        cout << " | " << boardCoordinates[i];
//    }
//    cout << " | " << endl;
//    cout << dottedLine << endl;
//    for (int i = 0; i < this->size; i++) {
//        cout << boardCoordinates[i] << "|";
//        for (int j = 0; j < this->size; j++) {
//            Status stat = this->cellArray[i][j];
//            switch (stat) {
//                case Empty:
//                    cout << "   |";
//                    break;
//                case White:
//                    cout << " O |";
//                    break;
//                case Black:
//                    cout << " X |";
//                    break;
//            }
//        }
//        cout << "" << endl;
//        cout << dottedLine << endl;
//    }
//}

Board::Status Board::getCellStatus(const Pair &p) const {
    if(p.getRow()>=0 && p.getRow() < this->getSize() && p.getCol() >=0 && p.getCol() < this->getSize()) {
        return this->cellArray[p.getRow()][p.getCol()];
    }
}

void Board::changeStatus(const Pair &p, Status s) {
    if(p.getRow()>=0 && p.getRow() < this->getSize() && p.getCol() >=0 && p.getCol() < this->getSize()) {
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

int Board::getSize() const{
    return this->size;
}

