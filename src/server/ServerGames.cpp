//
// Created by tomer on 12/25/17.
//
#include <cstring>
#include <iostream>
#include "ServerGames.h"
#include "../client/Pair.h"
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
//pthread_mutex_t mutexCommand;


ServerGames::ServerGames() {}

Room* ServerGames::getGame(string gameName) {
    cout << "started ServerGames::getGame " << endl;
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (gameName == it->getRoomName()) {
            cout << "ServerGames::getGame is now returning the room of game" << endl;
            return &(*it);
        }
        it++;
    }
    cout << "finishing ServerGames::getGame, it didn't return the room of game " << endl;
    return &(*it);
}

void ServerGames::addGame(string gameName, int clientSocket) {
    if (!isGameInList(gameName)) {
    Room *gameRoom = new Room(clientSocket, gameName);
    pthread_mutex_trylock(&mutexCommand);
    gamesList.push_back(*gameRoom);
    pthread_mutex_unlock(&mutexCommand);
    initializingPlayer(clientSocket, 1);
    }
}

void ServerGames::deleteGame(string gameName) {
    //delete thread.
    //earse from game list
    // delete room (after new)
    Room* roomToDelete = getGame(gameName);
    if(isGameInList(gameName)) {
        pthread_mutex_trylock(&mutexCommand);
        pthread_cancel(roomToDelete->getThread());
        gamesList.erase(getGameIterator(gameName));
        //delete room from list
        delete(roomToDelete);
        pthread_mutex_unlock(&mutexCommand);

    }
}

void ServerGames::joinToGame(string gameName, int clientSocket2) {
    if(isGameInList(gameName) && !getGame(gameName)->isRunning()) {
        Room* roomToJoin = getGame(gameName);
        pthread_mutex_trylock(&mutexCommand);
        roomToJoin->connectPlayer2(clientSocket2);
        initializingPlayer(clientSocket2, 2);
        initializingPlayer(roomToJoin->getOtherSocket(clientSocket2), 3);
        roomToJoin->startGame();
        pthread_mutex_unlock(&mutexCommand);

       // this->handleClients(roomToJoin.getOtherSocket(clientSocket2), clientSocket2);
        pthread_t currThread;
        twoClients sAC = twoClients(roomToJoin->getOtherSocket(clientSocket2), clientSocket2, this);
        int rc = pthread_create(&currThread, NULL, ServerGames::wrapHandleClients, &sAC);
        if (rc != 0) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
        pthread_mutex_trylock(&mutexCommand);
        roomToJoin->setThread(currThread);
        pthread_mutex_unlock(&mutexCommand);

        //connectionThreads.push_back(currThread);
    }
}

bool ServerGames::isGameRunning(string gameName) {
    cout << "started ServerGames::isGameRunning " << endl;
    bool isItRunning = false;
    cout << "ServerGames::isGameRunning called getGame" << endl;
    if (getGame(gameName)->isRunning()) {
        cout << "ServerGames::isGameRunning the game is running" << endl;
        isItRunning = true;
    }
    cout << "end ServerGames::isGameRunning" << endl;
    return isItRunning;
}
string ServerGames::sendListGames() {
    bool allRun = true;
    string list = "The available games are: ";
    if (gamesList.empty()) {
        list = "No available games to join.";
        return list;
    }
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if(!it->isRunning()) {
            cout << "added room to list of rooms:" << it->getRoomName() << endl;
            list += "\n                           " + it->getRoomName();
            allRun = false;
        }
        it++;
    }
    if(allRun) {
        list = "No available games to join.";
    }
    return list;
}

int ServerGames::size() {
    if(gamesList.empty()) {
        return 0;
    }
    int size = gamesList.size();
    return size;
}

bool ServerGames::isGameInList(string gameName) {
    cout << "ServerGames::isGameInList user gameName :   " << gameName << endl;
    if(!gamesList.empty()) {
        cout << "ServerGames::isGameInList gamelist isn't empty" << endl;
        cout << "ServerGames::isGameInList started iterating gamelist" << endl;
        vector<Room>::iterator it = gamesList.begin();
        while (it != gamesList.end()) {
            if (gameName == it->getRoomName()) {
                cout <<  "ServerGames::isGameInList return true- game in list " << endl;
                return true;
            }
            it++;
        }
        cout << "ServerGames::isGameInList finished iterating gamelist" << endl;
    }
    cout << "ServerGames::isGameInList the game isn't in the list"<< endl;
    return false;
}


void ServerGames::initializingPlayer(int playerSocket, int playerNum) {
    ssize_t x = write(playerSocket, &playerNum, sizeof(playerNum));
    if (x == -1) {
        cout << "Error writing to socket" << endl;
        exit(1);
    }
}

void ServerGames::handleClients(int player1, int player2) {
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

bool ServerGames::transferMessage(int sender, int receiver) {
    Pair pair;
    try {
        ssize_t checkTransfer = read(sender, &pair, sizeof(pair));
        if (checkTransfer <= 0) {
            return false;
        }
        // end of game
        if (pair.getCol() == -6 && pair.getCol() == -6) {
            deleteGame(findGame(sender, receiver));
            //finish thread
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

ServerGames *ServerGames::getInstance() {
    if (!instance) {
        instance = new ServerGames();
    }
    return instance;
}

ServerGames *ServerGames::instance = NULL;

ServerGames::~ServerGames() {
    if (!instance) {
        return;
    }
    delete(instance);
}

void* ServerGames::wrapHandleClients(void *args) {
    twoClients tC = * ((twoClients *) args);
    ((ServerGames*) tC.getServerGames())->handleClients(tC.getClient1(), tC.getClient2());
    return args;
}

bool ServerGames::hasAtLeastOneRunningGame() {
    if (this->gamesList.empty()) {
        return false;
    }
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (it->isRunning()) {
            return true;
        }
    }
    return false;
}

vector<Room>::iterator ServerGames::getGameIterator(string gameName) {
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (gameName == it->getRoomName()) {
            cout << "ServerGames::getGame is now returning the room of game" << endl;
            return it;
        }
        it++;
    }
    cout << "finishing ServerGames::getGame, it didn't return the room of game " << endl;
    return it;


}

string ServerGames::findGame(int player1, int player2) {
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (it->getPlayerSocket1() == player1 || it->getPlayerSocket1() == player1) {
            if(it->isRunning()) {
                return it->getRoomName();
            }
        }
        it++;
    }
    return "noGame";
}
