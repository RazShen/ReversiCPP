//
// Created by raz on 12/22/17.
//

#include <vector>
#include <unistd.h>
#include "StartNewGameC.h"


void StartNewGameC::execute(vector<string> args, int client, ServerGames* serverGamesI) {
    int i = 0;
    bool badName = false;
    // arg[01] is the room name
    string startString = args[1], answerToUser;
    for (i; i < serverGamesI->size(); i++) {
        if (serverGamesI->isGameInList(startString)) {
            badName = true;
        }
    }
    // user inputted a bad name
    if (!badName) {
        answerToUser = "AlreadyExist";
        writeToClient(answerToUser, client);
    } else {
        // send "started"
        answerToUser = "Started";
        writeToClient(answerToUser, client);
    }
}
