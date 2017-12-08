cmake_minimum_required(VERSION 3.6)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/Board.cpp src/Board.h src/GameLogic.cpp src/GameLogic.h src/RegularGameLogic.cpp
        src/RegularGameLogic.h src/HumanPlayer.h src/HumanPlayer.cpp src/AIPlayer.cpp src/AIPlayer.h src/Player.h
        src/Player.cpp src/Pair.cpp src/Pair.h src/ConsoleDisplay.cpp src/ConsoleDisplay.h src/Game.cpp src/Game.h
        src/Display.h src/server/Server.cpp src/server/Server.h src/client/RemotePlayerReceiver.cpp src/client/RemotePlayerReceiver.h
        src/RemoteGame.cpp src/RemoteGame.h src/client/RemotePlayerSender.cpp src/client/RemotePlayerSender.h)

set(TEST_FILES test/BoardTest.cpp test/GameLogicTest.cpp test/PossibleMovesTest.cpp )

add_executable(ex4 ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(ServerForReversi ${SOURCE_FILES} src/server/mainS.cpp)
add_executable(Reversi ${SOURCE_FILES} src/main.cpp)
target_link_libraries(ex4 gtest gtest_main pthread)
add_test(ex4 ex4)