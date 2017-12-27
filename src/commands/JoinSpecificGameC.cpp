//
// Created by raz on 12/22/17.
//

#include "JoinSpecificGameC.h"


void JoinSpecificGameC::execute(vector<string> args, int client, ServerGames* serverGamesI) {
    // go over all the rooms and find the room in arg[1]
    string wantedGameToJoin = args[1];
    string answerToUser = "notAvailableGame";
    if (serverGamesI->isGameInList(wantedGameToJoin)) {
        // game exist
        if (!serverGamesI->isGameRunning(wantedGameToJoin)) {
            cout << "JoinSpecificGameC -- game isn't running and game in list:  " << endl;
            // game exist and isn't running
            // join the game
            answerToUser = "JoiningGame";
            writeToClient(answerToUser, client);
            serverGamesI->joinToGame(wantedGameToJoin, client);
        } else {
            //game exist but running
            writeToClient(answerToUser, client);
        }
    } else {
        // game doesn't exist
        writeToClient(answerToUser, client);
    }
}
