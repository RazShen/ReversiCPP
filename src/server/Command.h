//
// Created by raz on 12/22/17.
//

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H
#include <vector>
#include <string>
using namespace std;
class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};
#endif //EX4_COMMAND_H
