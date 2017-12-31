//
// Created by raz on 12/22/17.
//

#include <vector>
#include "StartNewGameC.h"


void StartNewGameC::execute(vector<string> args, int client, ServerGames* serverGamesI) {
    int i = 0;
    bool badName = false;
    // arg[1] is the room name
    string gameName = args.at(1);
    string answerToUser;
    if (serverGamesI->isGameInList(gameName)) {
        badName = true;
    }
    // user inputted a bad name
    if (badName) {
        answerToUser = "AlreadyExist";
        writeToClient(answerToUser, client);
    } else {
        // send "started"
        answerToUser = "Started";
        writeToClient(answerToUser, client);
        serverGamesI->addGame(gameName, client);
    }
}
