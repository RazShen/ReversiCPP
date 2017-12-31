//
// Created by raz on 12/22/17.
//

#ifndef EX4_STARTNEWGAMEC_H
#define EX4_STARTNEWGAMEC_H



#include "Command.h"
#include "../client/Game.h"

#define STARTMESSAGE "Start"

class StartNewGameC : public Command {
public:
    /**
     * This method executes the command.
     * @param args inputted arguments
     * @param client socket.
     * @param serverGamesI- object that holds all the information about the games.
     */
    void execute(vector<string> args, int client, ServerGames* serverGamesI);
};
#endif //EX4_STARTNEWGAMEC_H
