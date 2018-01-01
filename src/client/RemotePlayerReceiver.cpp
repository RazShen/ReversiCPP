/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "RemotePlayerReceiver.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>
#define ERROR 30
using namespace std;


RemotePlayerReceiver::RemotePlayerReceiver(const char *filename) : Player(filename) {

}

void RemotePlayerReceiver::connectToServer(Display *display) {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    try {
        if (clientSocket == -1) {
            throw ERROR;
        }
    } catch (int e) {
        display->printString("Error opening socket");
        exit(1);
    }
    // Convert the ip string to a network address
    struct in_addr address;
    try {
        if (!inet_aton(serverIP.c_str(), &address)) {
            throw ERROR;
        }
    } catch (int e) {
        display->printString("Can't parse IP address");
        exit(1);
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
    try {
        if (server == NULL) {
            throw ERROR;
        }
    } catch (int e) {
        display->printString("Host is unreachable");
        exit(1);
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    try {
        if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
            throw ERROR;
        }
    } catch (int e) {
        display->printString("Error connecting to server");
        exit(1);
    }
}


int RemotePlayerReceiver::getMoveFromServer(Display *display) {
    ssize_t n;
    // Read the result from the server
    int result;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1 || n == 0) {
        throw ERROR;
    }

    return result;
}

const Pair
RemotePlayerReceiver::getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat,
                              Display *display) {
    display->waitingForOppToPlay();
    ssize_t n;
    Pair inputUser;
    n = read(clientSocket, &inputUser, sizeof(inputUser));
    if (n == -1 || n == 0) {
        throw ERROR;
    }
    if ((!gl->checkInput(inputUser, positions, moves, display)) || n == 0) {
        display->exitMassage();
        exit(1);
    }
    return inputUser;
}

void RemotePlayerReceiver::noMove(Display *display) {
    // just getting the pair -5,-5 from server to know opponent has no moves
    ssize_t n;
    Pair pair(0, 0);
    display->noPossiblePlayerMove(this->getType());
    n = read(clientSocket, &pair, sizeof(pair));
    if (n == -1 || n == 0) {
        throw ERROR;
    }
}

RemotePlayerReceiver::~RemotePlayerReceiver() {}

