//
// Created by raz on 12/22/17.
//

#include "CommandManager.h"

#include "StartNewGameC.h"
#include "JoinSpecificGameC.h"
#include "PlayMoveC.h"
#include "CloseSpecificGameC.h"
#include "GetListOfGamesC.h"
#include "../server/Server.h"

CommandsManager::CommandsManager(Server* server) this->server(server){
    commandsMap["start"] = new StartNewGameC();
    commandsMap["list_games"] = new GetListOfGamesC();
    commandsMap["join"] = new JoinSpecificGameC();
    commandsMap["Play"] = new PlayMoveC();
    commandsMap["close"] = new CloseSpecificGameC();
}

void CommandsManager::executeCommand(string command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
