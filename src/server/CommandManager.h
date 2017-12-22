//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMANDMANAGER_H
#define EX4_COMMANDMANAGER_H


#include <map>
#include "PrintCommand.h"

class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string command,
                        vector<string> args);
private:
    map<string, Command *> commandsMap;
};

#endif //EX4_COMMANDMANAGER_H
