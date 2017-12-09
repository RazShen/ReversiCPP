//
// Created by tomer on 12/2/17.
//

#include "RemotePlayerReceiver.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <limits>

using namespace std;

//RemotePlayerReceiver::RemotePlayerReceiver(const char *serverIP, int serverPort): serverIP(serverIP),
//                    serverPort(serverPort), clientSocket(0) {
//}

RemotePlayerReceiver::RemotePlayerReceiver(const char* filename): Player(filename) {

}

void RemotePlayerReceiver::connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
}



int RemotePlayerReceiver::getMoveFromServer() {
    ssize_t n;
    // Read the result from the server
    int result;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return result;
}

const Pair
RemotePlayerReceiver::getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display) {
    display->waitingForOppToPlay();
    int xUser;
    int yUser;
    ssize_t n;
    n = read(clientSocket, &xUser, sizeof(xUser));
    if (n == -1) {
    }
    n = read(clientSocket, &yUser, sizeof(yUser));
    if (n == -1) {
    }
    Pair inputUser = Pair(xUser, yUser);
    return inputUser;
}

void RemotePlayerReceiver::noMove(Display* display) {
    // just getting the pair -1,-1 from server to know opponent has no moves
    int xUser, yUser;
    ssize_t n;
    display->noPossiblePlayerMove(this->getType());
    n = read(clientSocket, &xUser, sizeof(xUser));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    n = read(clientSocket, &yUser, sizeof(yUser));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return;
}