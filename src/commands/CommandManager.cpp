//
// Created by raz on 12/22/17.
//

#include "CommandManager.h"
#include "StartNewGameC.h"
#include "JoinSpecificGameC.h"
#include "PlayMoveC.h"
#include "CloseSpecificGameC.h"
#include "GetListOfGamesC.h"


CommandsManager::CommandsManager(ServerGames* serverG): serverGames(serverG){
    commandsMap["start"] = new StartNewGameC();
    commandsMap["list_games"] = new GetListOfGamesC();
    commandsMap["join"] = new JoinSpecificGameC();
    commandsMap["Play"] = new PlayMoveC();
    commandsMap["close"] = new CloseSpecificGameC();

}

void CommandsManager::executeCommand(string command, vector<string> args) {
    int client = 0;
    Command *commandObj = commandsMap[command];
    commandObj->execute(args,client, this->serverGames);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
