//
// Created by raz on 12/22/17.
//

#include "Command.h"
#include <iostream>

class PrintCommand: public Command {
public:
    virtual void execute(vector<string> args) {
        for (int i = 0; i < args.size(); i++) {
            cout << args[i] << " ";
        }
        cout << endl;
    }
};

