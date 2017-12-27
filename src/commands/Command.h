//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H
#include <vector>
#include <iostream>
#include "../server/ServerGames.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

class Command {
public:
    virtual void execute(vector<string> args, int client, ServerGames* serverGamesI) = 0;
    void writeToClient(string inputForClient, int clientSocket);
    virtual ~Command() {}
};
#endif //EX4_COMMAND_H
