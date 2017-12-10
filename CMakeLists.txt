cmake_minimum_required(VERSION 3.6)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/client/Board.cpp src/client/Board.h src/client/GameLogic.cpp src/client/GameLogic.h src/client/RegularGameLogic.cpp
        src/client/RegularGameLogic.h src/client/HumanPlayer.h src/client/HumanPlayer.cpp src/client/AIPlayer.cpp src/client/AIPlayer.h src/client/Player.h
        src/client/Player.cpp src/client/Pair.cpp src/client/Pair.h src/client/ConsoleDisplay.cpp src/client/ConsoleDisplay.h src/client/Game.cpp src/client/Game.h
        src/client/Display.h src/server/Server.cpp src/server/Server.h src/client/RemotePlayerReceiver.cpp src/client/RemotePlayerReceiver.h
        src/client/RemotePlayerSender.cpp src/client/RemotePlayerSender.h)

set(TEST_FILES test/BoardTest.cpp test/GameLogicTest.cpp test/PossibleMovesTest.cpp )

add_executable(ex4 ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(ServerForReversi ${SOURCE_FILES} src/server/mainS.cpp)
add_executable(Reversi ${SOURCE_FILES} src/client/main.cpp)
target_link_libraries(ex4 gtest gtest_main pthread)
add_test(ex4 ex4)