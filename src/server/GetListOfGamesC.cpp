//
// Created by raz on 12/22/17.
//

#include "GetListOfGamesC.h"

void GetListOfGamesC::execute(vector<string> args, int client, ServerGames* serverGamesI) {
    //create list of room names and if it's not running put in vector to send
    writeToClient(serverGamesI->sendListGames(), client);
}

