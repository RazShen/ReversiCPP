//
// Created by raz on 12/22/17.
//

#include <unistd.h>
#include <vector>
#include "PlayMoveC.h"


void PlayMoveC::execute(vector<string> args, int client) {
    // get arg[0] as row get arg[1] as column
    string moveString;
    //Pair p = Pair((int) args[0])
    //string moveString = "Play " + args[0] + " " + args[1];
    write(client, &moveString, sizeof(string));
}