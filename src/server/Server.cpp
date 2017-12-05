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
    struct sockaddr_in serverAddress;
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
        int playerSocket1 = accept(serverSocket, (struct sockaddr *)&playerAddress1, &playerAddressLen1);
        cout << "Player X connected." << endl;
        if (playerSocket1 == -1)
            throw "Error on accept";

        cout << "Waiting for O player to connect..." << endl;
        // Accept a new client connection
        int playerSocket2 = accept(serverSocket, (struct sockaddr *)&playerAddress2, &playerAddressLen2);
        cout << "Player O connected." << endl;
        if (playerSocket2 == -1)
            throw "Error on accept";
        initializingPlayer(playerSocket1,1);
        initializingPlayer(playerSocket2,2);

        handleClients(playerSocket1, playerSocket2);
        // Close communication with the client
        close(playerSocket1);
        close(playerSocket2);
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
bool Server:: transferMessage(int sender, int receiver) {
    char buffer[MaxDataSize] = "\0";
    ssize_t checkTransfer = read(sender, buffer, sizeof(buffer));
    if (checkTransfer == -1) {
        return false;
    }
    checkTransfer = write(receiver, buffer, sizeof(receiver));
    if (checkTransfer == 0) {
        return false;
    }
    return true;



}
void Server::stop() {
    close(serverSocket);
}
