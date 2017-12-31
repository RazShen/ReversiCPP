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
#define ERROR 30
using namespace std;


RemotePlayerSender::RemotePlayerSender(const char *filename) : Player(filename) {

}

void RemotePlayerSender::connectToServer(Display* display) {
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
    playerMenu(display);
}

void RemotePlayerSender::update(int arg1, int arg2) {
    ssize_t n;
    // Write 2 numbers t
    Pair pair(arg1,arg2);
    n = write(clientSocket, &pair, sizeof(pair));
    if (n == -1 || n == 0) {
        throw ERROR;
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
    n = (int) read(clientSocket, &result, sizeof(int));
    if (n == -1 || n == 0) {
        throw ERROR;
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
    if (n == -1 || n == 0) {
        throw ERROR;
    }
    close(this->clientSocket);
}

RemotePlayerSender::~RemotePlayerSender() {}

void RemotePlayerSender::playerMenu(Display* display) {
    string command, roomName;
    int operation, n;
    bool inputILegal = true;
    // printing client's menu before joining game
    while(inputILegal) {
        display->printClientMenu();
        // get the operation of the client
        cin >> operation;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // illegal value in purpose
            operation = -5;
        }
        if(operation == 1 || operation == 3) {
            display->EnterNameOfGame();
            cin >> roomName;
        }
        if (operation == 1 || operation == 2 || operation == 3) {
            // translating the command from a number into string
            command = ParseOperation(operation, roomName);
            // sending the command to the server
            writeToServer(command);
            // reading the servers answer from the socket
            command = readFromServer();
            if (operation == 2) {
                // print the list of rooms
                display->printAvailableGames(command);
                connectToServer(display);
                break;
            } else if (command == "notAvailableGame") {
                // in option "join" - entering a name that isn't on the list
                display->notAvailableGame();
                connectToServer(display);
                break;
                // in option "start" - entering a name that is already on the list
            } else if (command == "AlreadyExist") {
                display->gameAlreadyExist();
                connectToServer(display);
                break;
                // in case user entered an option not from the menu
            } else if (command == "NotOption") {
                display->gameNotOption();
                connectToServer(display);
                break;
            }
            if (command == "Started") {
                // The input was legal
                inputILegal = false;
                string print = "The room: '" + roomName + "' was created!";
                display->printString(print);
                break;
            } else if (command == "JoiningGame") {
                // The input was legal
                inputILegal = false;
                string print = "You joined room:" + roomName + " !";
                display->printString(print);
                break;
            }
        } else {
            display->printString("No such option, try again");
        }
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


void RemotePlayerSender::writeToServer(string command) {
    int stringLength = command.length();
    int n;
    n = (int) write(clientSocket, &stringLength, sizeof(int));
    if (n == -1 || n == 0) {
        throw ERROR;
    }
    for (int i = 0; i < stringLength; i++) {
        n = (int) write(clientSocket, &command[i], sizeof(char));
        if (n == -1 || n == 0) {
            throw ERROR;
        }
    }
}

string RemotePlayerSender::readFromServer() {
    int stringLength, n;
    n = (int) read(clientSocket, &stringLength, sizeof(int));
    if (n == -1 || n == 0) {
        throw ERROR;
    }
    else {
        char *command = new char[stringLength + 1];
        for (int i = 0; i < stringLength; i++) {
            n = (int) read(clientSocket, &command[i], sizeof(char));
            if (n == -1 || n == 0) {
                throw ERROR;
            }
        }
        command[stringLength] = '\0';
        string strCommand(command);
        delete[] command;
        return strCommand;
    }
}
