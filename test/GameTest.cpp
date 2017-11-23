//
// Created by ori on 23/11/17.
//

#include "gtest/gtest.h"
#include "../src/Board.h"
#include "../src/GameLogic.h"
#include "../src/RegularGameLogic.h"
#include "../src/Game.h"

TEST(TestGame, Test2) {
    ConsoleDisplay display;
    Game game = Game(new RegularGameLogic(8, GameLogic::Regular), 1, &display);

    EXPECT_EQ(1,1);
}

