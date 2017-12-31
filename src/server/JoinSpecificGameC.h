//
// Created by raz on 12/22/17.
//

#ifndef EX4_JOINSPECIFICGAMEC_H
#define EX4_JOINSPECIFICGAMEC_H

#include "Command.h"
#include "../client/Game.h"

class JoinSpecificGameC : public Command {
public:
    /**
     * This method executes the command.
     * @param args inputted arguments
     * @param client socket.
     * @param serverGamesI- object that holds all the information about the games.
     */
    void execute(vector<string> args, int client, ServerGames* serverGamesI);
};

#endif //EX4_JOINSPECIFICGAMEC_H
