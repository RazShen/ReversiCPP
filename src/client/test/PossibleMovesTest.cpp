/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "gtest/gtest.h"
#include "../Board.h"
#include "../GameLogic.h"
#include "../RegularGameLogic.h"

/**
 * This test test the possible moves
 */
TEST(TestPossibleMoves, Test3) {
    int boardSize = 8;
    int index1 = 0;
    Pair possibleMoves1[4];
    possibleMoves1[0] = Pair(2,3);
    possibleMoves1[1] = Pair(3,2);
    possibleMoves1[2] = Pair(4,5);
    possibleMoves1[3] = Pair(5,4);
    Pair gLPossibleMoves[4];
    GameLogic* gL = new RegularGameLogic(boardSize, GameLogic::Regular);
    gL->possibleMoves(gLPossibleMoves, index1, Board::Black);
    // check the possible moves in a new board and X starts
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(possibleMoves1[i].getRow(), gLPossibleMoves[i].getRow());
        EXPECT_EQ(possibleMoves1[i].getCol(), gLPossibleMoves[i].getCol());
    }
    //set the board to be empty
    gL->getBoard()->changeStatus(Pair(3,4), Board::Empty);
    gL->getBoard()->changeStatus(Pair(4,3), Board::Empty);
    gL->getBoard()->changeStatus(Pair(5,6), Board::Empty);
    gL->getBoard()->changeStatus(Pair(6,5), Board::Empty);
    Pair gLShouldBeNoMoves[4];
    int index2 = 0;
    gL->possibleMoves(gLShouldBeNoMoves, index2, Board::Black);
    // check that indeed in empty board there are no possible moves
    EXPECT_EQ(index2, 0);

    delete(gL);
}