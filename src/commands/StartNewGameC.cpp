//
// Created by raz on 12/22/17.
//

#include <vector>
#include <unistd.h>
#include "StartNewGameC.h"


void StartNewGameC::execute(vector<string> args, vector<Game> games, int client) {
    string startString;
    //string startString = STARTMESSAGE;
    write(client, &startString, sizeof(string));
}
