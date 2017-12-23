/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "RemotePlayerSender.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <limits>
#include <cstdlib>

using namespace std;


RemotePlayerSender::RemotePlayerSender(const char *filename) : Player(filename) {

}

void RemotePlayerSender::connectToServer(Display* display) {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP.c_str(), &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *) &address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *) &serverAddress.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    playerMenu(display);
}

void RemotePlayerSender::update(int arg1, int arg2) {
    ssize_t numToSend;
    // Write 2 numbers t
    Pair pair(arg1,arg2);
    numToSend = write(clientSocket, &pair, sizeof(pair));
    if (numToSend == -1) {
        throw "Error writing arg1 to socket";
    }
}

const Pair
RemotePlayerSender::getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display) {
    int xUser, yUser;
    display->itsYourMove(this->getType());
    display->possibleMoves(positions, moves);
    display->getInput();
    cin >> xUser >> yUser;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // illegal value in purpose
        xUser = -5;
        yUser = -5;
    }
    Pair inputUser = Pair(xUser, yUser);
    return inputUser;
}

int RemotePlayerSender::getMoveFromServer() {
    ssize_t n;
    // Read the result from the server
    int result;
    n = read(clientSocket, &result, sizeof(result));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    return result;
}

void RemotePlayerSender::noMove(Display *display) {
    string anyKey;
    display->noPossiblePlayerMove(this->getType());
    display->pressAnyKey();
    getline(cin, anyKey);
    if(anyKey == "\n") {
        cout << "\n";
        getline(cin, anyKey);
    }
    display->newLine();
    update(-1, -1);
}

void RemotePlayerSender::finishGame() {
    Pair pair1(-6,-6);
    ssize_t n;
    n = write(this->clientSocket, &pair1, sizeof(pair1));
    if (n == -1) {
        throw "Error reading result from socket";
    }
    close(this->clientSocket);
}

RemotePlayerSender::~RemotePlayerSender() {}

void RemotePlayerSender::playerMenu(Display * display) {

    string command, name;
    int operation, n;
    bool inputILegal = true;
    ConsoleDisplay printer ;
    // printing client's menu before joining game
    while(inputILegal) {
        printer.printClientMenu();
        // get the operation of the client
        cin >> operation;

        if(operation == 1 || operation == 3) {
            printer.EnterNameOfGame();
            cin >> name;
        }
        //
        // translating the command from a number into string
        command = ParseOperation(operation, name);
        // sending the command to the server
        n = write(clientSocket, &command, command.size());
        if (n <= 0) {
            throw "Error writing command to socket";
        }
        // reading the servers answer from the socket
        n = read(clientSocket, &command, command.size());
        // for problems with reading from the socket
        if (n <= 0) {
            throw "Error writing command to socket";
        }

        // in option "join" - entering a name that isn't on the list
        if (command == "NotExist") {
            printer.gameNotExist();
            continue;
            // in option "start" - entering a name that is already on the list
        } else if(command == "AlreadyExist") {
            printer.gameAlreadyExist();
            continue;
            // in case user entered an option not from the menu
        } else if(command == "NotOption") {
            printer.gameNotOption();
            continue;
        }
        // if the input was legal
        inputILegal = false;
    }


}

string RemotePlayerSender::ParseOperation(int operation, string name) {
    switch(operation) {
        case 1:
            return "start " + name;
        case 2:
            return "list_games";
        case 3:
            return "join " + name;
        default:
            return "NotOption";
    }
}
