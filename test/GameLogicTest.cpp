//
// Created by ori on 23/11/17.
//

#include "gtest/gtest.h"
#include "../src/GameLogic.h"
#include "../src/RegularGameLogic.h"


TEST(TestGameLogic, Test1) {
    int boardSize = 8;
    GameLogic* gl = new RegularGameLogic(boardSize, GameLogic::Regular);

    EXPECT_EQ(gl->getBlackScore(),0);
    EXPECT_EQ(gl->whoWon(),GameLogic::Draw);

    gl->getBoard()->changeStatus(Pair(1,1), Board::Black);
    EXPECT_EQ(gl->getBlackScore(),1);
    EXPECT_EQ(gl->whoWon(),GameLogic::BlackWon);
    delete(gl);
}

