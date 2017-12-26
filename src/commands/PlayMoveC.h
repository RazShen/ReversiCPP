//
// Created by raz on 12/22/17.
//

#ifndef EX4_PLAYMOVEC_H
#define EX4_PLAYMOVEC_H


#include "../client/Game.h"
#include "Command.h"

class PlayMoveC : public Command {
public:
    void execute(const vector<string>& args, int client, ServerGames* serverGamesI);
};
#endif //EX4_PLAYMOVEC_H
