//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMANDMANAGER_H
#define EX4_COMMANDMANAGER_H


#include <map>
#include "Command.h"
#include "../server/Server.h"
#include "../server/ServerGames.h"


class CommandsManager {
public:
    CommandsManager(ServerGames* serverG);
    ~CommandsManager();
    void executeCommand(string command, vector<string> args);
private:
    map<string, Command *> commandsMap;
    ServerGames* serverGames;
};

#endif //EX4_COMMANDMANAGER_H
