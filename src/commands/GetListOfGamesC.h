//
// Created by raz on 12/22/17.
//

#ifndef EX4_GETLISTOFGAMESC_H
#define EX4_GETLISTOFGAMESC_H



#include "Command.h"
#include "../client/Game.h"

class GetListOfGamesC : public Command {
public:
    void execute(vector<string> args, int client = 0, ServerGames* serverGames);
};


#endif //EX4_GETLISTOFGAMESC_H
