//
// Created by raz on 12/2/17.
//

#include <iostream>
#include <cstdlib>
//#include <sys/socket.h>
//#include <stdio.h>
//#include <string.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <unistd.h>
#include "Server.h";

using namespace std;

int main() {
//    const int serverPort = 6667;
//
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock < 0) {
//        // Error opening socket
//         perror("Can't open socket");
//        return 0;
//    }
//
//    struct sockaddr_in sin;
//    // initialize to a no value socket
//    memset(&sin, 0, sizeof(sin));
//
//    // initialize values
//    sin.sin_family = AF_INET;
//    sin.sin_addr.s_addr = INADDR_ANY;
//    sin.sin_port = htons(serverPort);
//
//    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
//        // Error binding
//         perror("Can't bind");
//        return 0;
//    }
//
//    // listen
//
//    // accept
//    //read() write()
//
    Server server(6557);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
