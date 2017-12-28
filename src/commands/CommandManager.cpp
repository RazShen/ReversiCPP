//
// Created by raz on 12/22/17.
//

#include "CommandManager.h"
#include "StartNewGameC.h"
#include "JoinSpecificGameC.h"
#include "CloseSpecificGameC.h"
#include "GetListOfGamesC.h"


CommandManager::CommandManager(ServerGames* serverG): serverGames(serverG){
    commandsMap["start"] = new StartNewGameC();
    commandsMap["list_games"] = new GetListOfGamesC();
    commandsMap["join"] = new JoinSpecificGameC();
    commandsMap["close"] = new CloseSpecificGameC();

}

void CommandManager::executeCommand(string command, vector<string> args, int client) {
    Command *commandObj = commandsMap[command];
    vector<string> arguments = args;
    cout << "commandManager execute command:   " << command << endl;
    commandObj->execute(arguments,client, this->serverGames);
}

CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}
