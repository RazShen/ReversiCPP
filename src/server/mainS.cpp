/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#define MAXLINE 20
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "Server.h"

using namespace std;

int main() {
    int serverPort1, serverPort2;
    string buffer;
    char portBuf[MAXLINE];
    ifstream settings;
    settings.open("sconfig.txt");
    if(!settings){
        throw "Can't open file, aborting";
    }
    getline(settings,buffer);
    sscanf(buffer.c_str(), "%s : %d", portBuf , &serverPort1);
    if (!strcmp(portBuf, "Port")) {
        serverPort2 = serverPort1;
    } else {
        settings.close();
        throw "cannot parse the port";
    }
    settings.close();
    Server server(serverPort2);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
