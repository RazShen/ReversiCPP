/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "gtest/gtest.h"
#include "../GameLogic.h"
#include "../RegularGameLogic.h"

/**
 * This class tests the Game logic.
 */
TEST(TestGameLogic, Test1) {
    int boardSize = 8;
    GameLogic* gl = new RegularGameLogic(boardSize, GameLogic::Regular);
    // new game logic with new default board
    EXPECT_EQ(gl->getBlackScore(),0);
    EXPECT_EQ(gl->whoWon(),GameLogic::Draw);

    gl->getBoard()->changeStatus(Pair(1,1), Board::Black);
    // 3 black cells and 2 white cells are now in the board
    EXPECT_EQ(gl->getBlackScore(),1);
    EXPECT_EQ(gl->whoWon(),GameLogic::BlackWon);
    delete(gl);
}

