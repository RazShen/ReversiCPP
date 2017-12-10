/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */



#include "Pair.h"

Pair::Pair() {
}

Pair::Pair(int row, int column) {
    this->row = row;
    this->column = column;
}

int Pair::getRow() const {
    return this->row;
}

int Pair::getCol() const {
    return this->column;
}

