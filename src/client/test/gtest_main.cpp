/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <gtest/gtest.h>


using namespace testing;

/**
* This is the main that runs the tests.
*/
int main(int argc, char *argv[]) {
    InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    return 0;
}

//DELETE MAIN.CPP FROM THE ORIGINAL PROJECT