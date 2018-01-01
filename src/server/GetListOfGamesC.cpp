//
// Created by raz on 12/22/17.
//

#include "GetListOfGamesC.h"

void GetListOfGamesC::execute(vector<string> args, int client, ServerGames* serverGamesI) {
    writeToClient(serverGamesI->sendListGames(), client);
}

