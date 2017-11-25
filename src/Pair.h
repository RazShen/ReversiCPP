/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


/*
 * Pair.h
 *  Struct of a Pair in order to describe a location for the cell.
 *  Created on: Nov 3, 2017
 *  Author: Raz Shenkman
 */


#ifndef EX2_PAIR_H
#define EX2_PAIR_H

#include <string>

using namespace std;

struct Pair {
public:
    /**
     * Constructor for pair from row and column.
     * @param row row.
     * @param column column.
     */
    Pair(int row, int column);


    /**
     * Empty constructor for pair.
     */
    Pair();

    /**
     * This method returns the row of the pair.
     * @return row.
     */
    int getRow() const;

    /**
     * This method returns the column of the pair.
     * @return column.
     */
    int getCol() const;


private:
    // Row and column integers.
    int row, column;
};

#endif //EX2_PAIR_H