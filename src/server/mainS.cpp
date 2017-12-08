//
// Created by raz on 12/2/17.
//

#include <iostream>
#include <cstdlib>
#include <fstream>

#include "Server.h"

using namespace std;

int main() {
    int serverPort;
    string buffer;
    ifstream settings;
    settings.open("serversettings.txt");
    if(!settings){
        throw "Can't open file, aborting";
    }
    while (!settings.eof()) {
        settings >> buffer;
        if (buffer == "Port") {
            settings >> buffer; // buffer is now ":"
            settings >> buffer;
            serverPort = atoi(buffer.c_str());
        }
    }
    settings.close();
    Server server(serverPort);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
