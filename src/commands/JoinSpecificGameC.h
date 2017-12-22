//
// Created by raz on 12/22/17.
//

#ifndef EX4_JOINSPECIFICGAMEC_H
#define EX4_JOINSPECIFICGAMEC_H

#include "Command.h"
#include "../client/Game.h"

class JoinSpecificGameC : public Command {
public:
    void execute(vector<string> args, vector<Game> games, int client = 0);
    void execute(vector<string> args, int client = 0) {};
};

#endif //EX4_JOINSPECIFICGAMEC_H
