//
// Created by raz on 12/22/17.
//

#include <unistd.h>
#include <vector>
#include <cstdio>
#include "PlayMoveC.h"


void PlayMoveC::execute(const vector<string>& args, int client, ServerGames* serverGamesI) {
    // get arg[0] as row get arg[1] as column
    string moveString;
    int row, column, i =0;
    sscanf(args[0].c_str(), "%d", &row);
    sscanf(args[1].c_str(), "%d", &column);
    Pair p = Pair(row, column);
    // send this pair to the other player in the room
    for (i; i < serverGamesI->size(); i++) {
    //tu    if (client == serverGames->getGame())
    }
    //string moveString = "Play " + args[0] + " " + args[1];
    write(client, &moveString, sizeof(string));
}