//
// Created by raz on 12/22/17.
//

#include <vector>
#include <unistd.h>
#include "StartNewGameC.h"


void StartNewGameC::execute(vector<string> args, int client, ServerGames* serverGames) {
    // arg[01] is the room name
    string startString;
    //string startString = STARTMESSAGE;
    write(client, &startString, sizeof(string));

}
