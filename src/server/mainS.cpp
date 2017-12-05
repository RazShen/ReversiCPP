//
// Created by raz on 12/2/17.
//

#include <iostream>
#include <cstdlib>

#include "Server.h"

using namespace std;

int main() {

    Server server(6557);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
