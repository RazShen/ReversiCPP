//
// Created by raz on 12/2/17.
//

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <cstdlib>

#define MaxDataSize 20

using namespace std;
#define MAX_CONNECTED_CLIENTS 2
Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}


void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress = {};
    bzero((void *) &serverAddress,
          sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in playerAddress1;
    struct sockaddr_in playerAddress2;
    socklen_t playerAddressLen1;
    socklen_t playerAddressLen2;
    while (true) {
        cout << "Waiting for X player to connect..." << endl;
        // Accept a new client connection
        int player1 = accept(serverSocket, (struct sockaddr *)&playerAddress1, &playerAddressLen1);
        cout << "Player X connected." << endl;
        if (player1 == -1)
            throw "Error on accept";

        cout << "Waiting for O player to connect..." << endl;
        initializingPlayer(player1,1);
        // Accept a new client connection
        int player2 = accept(serverSocket, (struct sockaddr *)&playerAddress2, &playerAddressLen2);
        cout << "Player O connected." << endl;
        if (player2 == -1)
            throw "Error on accept";
     //   initializingPlayer(player1,1);

        initializingPlayer(player2,2);
        initializingPlayer(player1,3);
        handleClients(player1, player2);
        // Close communication with the client
        close(player1);
        close(player2);
    }
}
void Server:: initializingPlayer(int playerSocket, int playerNum) {
    ssize_t x = write(playerSocket, &playerNum, sizeof(playerNum));
    if(x == -1) {
        cout << "Error writing to socket" << endl;
        exit(1);
    }

}
void Server::handleClients(int player1, int player2) {
    int sender = player1;
    int receiver = player2;
    int temp;
    while (transferMessage(sender, receiver)) {
        temp = sender;
        sender = receiver;
        receiver = temp;
    }
}
bool Server::transferMessage(int sender, int receiver) {
    cout << sender << endl;
    cout << receiver << endl;
    int arg1, arg2;
    ssize_t checkTransfer = read(sender, &arg1, sizeof(arg1));
    cout << "server read" << arg1 << endl;
    if (checkTransfer <= 0) {
        return false;
    }
    checkTransfer = read(sender, &arg2, sizeof(arg2));
    cout << "server read" << arg2 << endl;

    if (checkTransfer <= 0) {
        return false;
    }
    checkTransfer = write(receiver, &arg1, sizeof(arg1));
    cout << "server wrote" << arg1 << endl;
    if (checkTransfer <= 0) {
        return false;
    }
    checkTransfer = write(receiver, &arg2, sizeof(arg2));
    cout << "server wrote" << arg2 << endl;
    if (checkTransfer <= 0) {
        return false;
    }
    return true;
}

void Server::stop() {
    close(serverSocket);
}

