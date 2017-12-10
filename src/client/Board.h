/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef BOARD_H_
#define BOARD_H_

#include "Pair.h"

/**
 * This class features a game board.
 */
class Board {
public:
    //Enum for the status of the cell
    enum Status {
        Empty, White, Black
    };

    /**
    * This constructor creates a board from an inputted size.
    * @param size- wanted size for the board.
    */
    Board(int &size);

    /**
     * This function clons a board.
     * @param b inputted board.
     */
    Board(const Board &b);

    /**
    * This method returns status of desired cell.
    * @param p inputted pair for getting the cell.
    * @return cell's status.
    */
    Status getCellStatus(const Pair &p) const;

    /**
    * This method changes status of desired cell.
    * @param p inputted pair for getting the cell.
    * @param s desired input status.
    */
    void changeStatus(const Pair &p, Status s);

    /**
     * This method checks if all the board cells have values in them.
     * @return true/false.
     */
    bool isBoardFull() const;

    /**
     * Return the size of the board.
     * @return
     */
    int getSize() const;

    /**
    * Destructor for the board.
    */
    ~Board();

    /**
     * this method gets the matrix of the board
     * @return the matrix of the board
     */
    Status **getMatrix();

private:
    // The cells of the board.
    Status **cellArray;
    int size;
};

#endif /* BOARD_H_ */