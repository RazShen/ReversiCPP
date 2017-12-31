//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMANDMANAGER_H
#define EX4_COMMANDMANAGER_H


#include <map>
#include "Command.h"
#include "ServerGames.h"


class CommandManager {
public:
    /**
     * Constructor for commandmanager from a pointer to servergames.
     * @param serverG
     */
    CommandManager(ServerGames* serverG);
    ~CommandManager();
    /**
     * This method executes the command.
     * @param args inputted arguments
     * @param client socket.
     * @param serverGamesI- object that holds all the information about the games.
     */
    void executeCommand(string command, vector<string> args, int client);
private:
    map<string, Command *> commandsMap;
    ServerGames* serverGames;
};

#endif //EX4_COMMANDMANAGER_H
