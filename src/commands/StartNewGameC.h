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
    void execute(vector<string> args, vector<Game> games, int client = 0);
    void execute(vector<string> args, int client = 0) {};
};
#endif //EX4_STARTNEWGAMEC_H
