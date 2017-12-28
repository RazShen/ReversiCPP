/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#include "Server.h"
#include "../client/Pair.h"
#include <string.h>
#include <cstdlib>
#include <pthread.h>




using namespace std;
#define MAX_CONNECTED_CLIENTS 10
#define THREADS_NUM 10


Server::Server(int port) : port(port), serverSocket(0) {
    cout << "Server" << endl;
    this->shouldStop = false;
}


void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress = {};
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        this->stop();
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in playerAddress1;
    struct sockaddr_in playerAddress2;
    socklen_t playerAddressLen1 = 0;
    socklen_t playerAddressLen2 = 0;
    int player1, player2;
    pthread_t currThread2;
    serverS serv = serverS(this);
    int bc = pthread_create(&currThread2, NULL, Server::changeShouldStop, &serv);
    if (bc != 0) {
        cout << "Error: unable to create thread, " << bc << endl;
        exit(-1);
    }
    while (!shouldStop) {
        cout << "Waiting for connections..." << endl;
        if (shouldStop) {
            cout << "exit" << endl;
        }
        // Accept a new client connection
        player1 = accept(serverSocket, (struct sockaddr *) &playerAddress1, &playerAddressLen1);
        if (player1 == -1) {
            this->stop();
            throw "Error on accept";
        }
        cout << "Player connected." << endl;
        cout << "started handlebeforeclientThread" << endl;
        pthread_t currThread;
        serverAndClient sAC = serverAndClient(this, player1);
        int rc = pthread_create(&currThread, NULL, Server::handleAccept2, &sAC);
        if (rc != 0) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
        connectionThreads.push_back(currThread);
       //handleBeforeClient(player1);
        cout << "ended handlebeforeclientThread" << endl;
        if (shouldStop) {
            cout << "exit" << endl;
        }
//        //have a connection
//        handleClients(player1, player2);
    }
}

void Server::initializingPlayer(int playerSocket, int playerNum) {
    ssize_t x = write(playerSocket, &playerNum, sizeof(playerNum));
    if (x == -1) {
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
    // Close communication with the client
    close(player1);
    close(player2);
}

bool Server::transferMessage(int sender, int receiver) {
    Pair pair;
    try {
        ssize_t checkTransfer = read(sender, &pair, sizeof(pair));
        if (checkTransfer <= 0) {
            return false;
        }
        // end of game
        if (pair.getCol() == -6 && pair.getCol() == -6) {
            return false;
        }
        checkTransfer = write(receiver, &pair, sizeof(pair));
        if (checkTransfer <= 0) {
            return false;
        }
    } catch(exception e) {
            return false;
    }
    return true;
}

void Server::stop() {
    close(serverSocket);
}

void Server::handleBeforeClient(int clientSocket) {
    ServerGames* sG = ServerGames::getInstance();
    CommandManager commandManager = CommandManager(sG);
    // in this method we get the user input and run the command by command manager
    string input = "", wantedCommand;
    vector<string> inputtedStringInVec;
    input = readFromClient(clientSocket);
    cout << "handleBeforeClient read:" << input << endl;
    if (input != "list_games") {
        cout << "down in !list_games" << endl;
        inputtedStringInVec = parseStringBySpace(input);
        cout << "Parse of vector handleBeforeClient read:" << inputtedStringInVec.at(0) << "    "  << inputtedStringInVec.at(1) << endl;
        wantedCommand = inputtedStringInVec.at(0);
    } else {
        cout << "down in list_games" << endl;
        wantedCommand = input;
        inputtedStringInVec.push_back(input);
    }
    commandManager.executeCommand(wantedCommand, inputtedStringInVec, clientSocket);
}

vector<string>  Server::parseStringBySpace(string str) {
    vector<string> result;
    string parser = " ";
    while(str.size()){
        unsigned long index = str.find(parser);
        if(index!= string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+parser.size());
            if(str.size()==0)result.push_back(str);
        }else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

string Server::readFromClient(int clientSocket) {
    int stringLength, n;
    n = (int) read(clientSocket, &stringLength, sizeof(int));
    cout << "readFromClient read stringLength: " << stringLength << endl;
    if (n == -1)
        throw "Error reading string length";
    char *command = new char[stringLength + 1];
    for (int i = 0; i < stringLength; i++) {
        n = (int) read(clientSocket, &command[i], sizeof(char));
        if (n == -1)
            throw "Error reading message!";
    }
    command[stringLength] = '\0';
    string strCommand(command);
    cout << "server  read from client" << command << endl;
    delete(command);
    return strCommand;

}

void *Server::handleAccept(void *tempArgs) {
    cout << "Entered handleAccept" << endl;
    int clientSocket = *((int *) tempArgs);
    cout << "got clientSocket in handleAccept:   " << clientSocket << endl;
    ((Server *) tempArgs)->handleBeforeClient(clientSocket);
    return tempArgs;
}

void *Server::handleAccept2(void *structOfserver) {
    cout << "Entered handleAccept" << endl;
    serverAndClient sAC = *((serverAndClient *) structOfserver);
    ((Server *) sAC.getServer())->handleBeforeClient(sAC.getClientS());
    cout << "Finished handleAccept" << endl;
    return structOfserver;
}

void Server::stopServer() {
    this->shouldStop = true;
    cout <<  2 << endl;
}

void* Server::changeShouldStop(void *args) {
    Server* server = (Server*) args;
    cout << "type ""exit"" then press ENTER to stop the server and all the running games" << endl;
    string input = "";
    do {
        if (input == "exit") {
            cout << 1 << endl;
            server->shouldStop = true;
        }
        cin >> input;
    } while (true);
}