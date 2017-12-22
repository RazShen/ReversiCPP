//
// Created by raz on 12/22/17.
//

#include <unistd.h>
#include <vector>
#include "PlayMoveC.h"


void PlayMoveC::execute(vector<string> args, vector<Game> games, int client) {
    string moveString;
    //string moveString = "Play " + args[0] + " " + args[1];
    write(client, &moveString, sizeof(string));
}