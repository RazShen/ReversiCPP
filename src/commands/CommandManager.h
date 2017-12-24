//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMANDMANAGER_H
#define EX4_COMMANDMANAGER_H


#include <map>
#include "Command.h"
#include "../server/Server.h"


class CommandsManager {
public:
    CommandsManager(Server* serverC);
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);
private:
    map<string, Command *> commandsMap;
    Server* server;
};

#endif //EX4_COMMANDMANAGER_H
