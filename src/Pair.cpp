//ID: 311130777
//Name: Raz Shenkman
/*
 * Pair.cpp
 *  Struct of a Pair in order to describe a location for the cell.
 *  Created on: Nov 3, 2017
 *  Author: Raz Shenkman
 */

#include <iostream>
#include "Pair.h"

Pair::Pair() {
}

Pair::Pair(int row, int column) {
    this->row = row;
    this->column = column;
}

void Pair::print() const {
    cout << "(" << this->row + 1 << "," << this->column + 1 << ")";
}

int Pair::getRow() const {
    return this->row;
}

int Pair::getCol() const {
    return this->column;
}

