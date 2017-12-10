/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "gtest/gtest.h"
#include "../Board.h"

/**
 * This class tests the Board.
 */
TEST(TestBoard, Test2) {
    int size = 8;
    Board board = Board(size);
    // check the default board (4 cells in the middle)
    EXPECT_EQ(board.getCellStatus(Pair(3,4)), Board::Black);
    // the board isn't full
    EXPECT_EQ(board.isBoardFull(),false);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board.changeStatus(Pair(i, j), Board::Black);
        }
    }
    // the board is full now
    EXPECT_EQ(board.isBoardFull(),true);
    Board::Status stat = board.getCellStatus(Pair(99,99));
    // get default value
    EXPECT_EQ(stat, 0);
}