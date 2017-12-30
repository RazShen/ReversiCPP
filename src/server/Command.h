//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H
#include <vector>
#include <iostream>
#include "ServerGames.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

class Command {
public:
    /**
     * Execute a command.
     * @param args string of arguments.
     * @param client client socket to use.
     * @param serverGamesI information of the server games.
     */
    virtual void execute(vector<string> args, int client, ServerGames* serverGamesI) = 0;
    /**
     * Write to client.
     * @param inputForClient input string to write.
     * @param clientSocket client socket to write to.
     */
    void writeToClient(string inputForClient, int clientSocket);
    /**
     * Destructor for command.
     */
    virtual ~Command() {}
};
#endif //EX4_COMMAND_H
