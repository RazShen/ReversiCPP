//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMANDMANAGER_H
#define EX4_COMMANDMANAGER_H


#include <map>
#include "Command.h"
#include "../server/ServerGames.h"


class CommandManager {
public:
    CommandManager(ServerGames* serverG);
    ~CommandManager();
    void executeCommand(string command, vector<string> args, int client);
private:
    map<string, Command *> commandsMap;
    ServerGames* serverGames;
};

#endif //EX4_COMMANDMANAGER_H
