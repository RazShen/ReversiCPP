/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#include "Server.h"
#include <string.h>
#include <cstdlib>




using namespace std;
#define MAX_CONNECTED_CLIENTS 10


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
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    // Define the client socket's structures
    struct sockaddr_in playerAddress1;
    socklen_t playerAddressLen1 = 0;
    int player1;
    pthread_t serverThread;
    int bc = pthread_create(&serverThread, NULL, Server::changeShouldStop, this);
    if (bc != 0) {
        cout << "Error: unable to create thread, " << bc << endl;
        exit(-1);
    }
    threadServer = serverThread;
    while (!shouldStop) {
        // Accept a new client connection
        player1 = accept(serverSocket, (struct sockaddr *) &playerAddress1, &playerAddressLen1);
        if (player1 == -1 || player1 == 0) {
            this->stop();
            return;
        }
        pthread_t currThread;
        serverAndClient sAC = serverAndClient(this, player1);
        int rc = pthread_create(&currThread, NULL, Server::handleAccept, &sAC);
        if (rc != 0) {
            exit(-1);
        }
        pthread_join(currThread, NULL);
        connectionThreads.push_back(currThread);
        if(shouldStop) {
            this->stop();
            return;
        }
    }
}


void Server::stop() {
    shouldStop = true;
    ServerGames* sG = ServerGames::getInstance();
    sG->deleteAllGames();
    // close threads
    vector<pthread_t>::iterator it = connectionThreads.begin();
    while (it != connectionThreads.end()) {
        pthread_cancel(*it);
        it++;
    }
    pthread_cancel(threadServer);
    shutdown(serverSocket, SHUT_RDWR);
    close(serverSocket);
    return;
}

void Server::handleBeforeClient(int clientSocket) {
    ServerGames* sG = ServerGames::getInstance();
    CommandManager commandManager = CommandManager(sG);
    // in this method we get the user input and run the command by command manager
    string input = "", wantedCommand;
    vector<string> inputtedStringInVec;
    input = readFromClient(clientSocket);
    if (input != "list_games") {
        inputtedStringInVec = parseStringBySpace(input);
        wantedCommand = inputtedStringInVec.at(0);
    } else {
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
    delete[] command;
    return strCommand;

}

void *Server::handleAccept(void *structOfServer) {
        serverAndClient sAC = *((serverAndClient *) structOfServer);
    (sAC.getServer())->handleBeforeClient(sAC.getClientS());
    return structOfServer;
}

void* Server::changeShouldStop(void *args) {
    Server* server = (Server*) args;
    string input;
    while (input != "exit") {
        cout << "type ""exit"" then press ENTER to stop the server and all the running games" << endl;
        cin >> input;
    }
    server->stop();
    pthread_detach(pthread_self());
    exit(1);
}
