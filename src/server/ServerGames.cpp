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


ServerGames::ServerGames() {
    pthread_mutex_init(&mutexCommand, NULL);
}

Room* ServerGames::getGame(string gameName) {
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (gameName == it->getRoomName()) {
            return &(*it);
        }
        it++;
    }
    return &(*it);
}

void ServerGames::addGame(string gameName, int clientSocket) {
    if (!isGameInList(gameName)) {
    Room gameRoom = Room(clientSocket, gameName);
    pthread_mutex_lock(&mutexCommand);
    gamesList.push_back(gameRoom);
    pthread_mutex_unlock(&mutexCommand);
    initializingPlayer(clientSocket, 1);
    }
}

void ServerGames::deleteGame(string gameName) {
    Room* roomToDelete = getGame(gameName);
    if(isGameInList(gameName)) {
        pthread_cancel(roomToDelete->getThread());
        gamesList.erase(getGameIterator(gameName));
    }
}

void ServerGames::joinToGame(string gameName, int clientSocket2) {
    if(isGameInList(gameName) && !getGame(gameName)->isRunning()) {
        Room* roomToJoin = getGame(gameName);
        pthread_mutex_lock(&mutexCommand);
        roomToJoin->connectPlayer2(clientSocket2);
        initializingPlayer(clientSocket2, 2);
        initializingPlayer(roomToJoin->getOtherSocket(clientSocket2), 3);
        roomToJoin->startGame();
        pthread_mutex_unlock(&mutexCommand);

       // this->handleClients(roomToJoin.getOtherSocket(clientSocket2), clientSocket2);
        pthread_t currThread;
        twoClients* sAC = new twoClients(roomToJoin->getOtherSocket(clientSocket2), clientSocket2, this);
        int rc = pthread_create(&currThread, NULL, ServerGames::wrapHandleClients, sAC);
        if (rc != 0) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }
        pthread_mutex_lock(&mutexCommand);
        roomToJoin->setThread(currThread);
        pthread_mutex_unlock(&mutexCommand);

        //connectionThreads.push_back(currThread);
    }
}

bool ServerGames::isGameRunning(string gameName) {
    bool isItRunning = false;
    if (getGame(gameName)->isRunning()) {
        isItRunning = true;
    }
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
    if(!gamesList.empty()) {
        vector<Room>::iterator it = gamesList.begin();
        while (it != gamesList.end()) {
            if (gameName == it->getRoomName()) {
                return true;
            }
            it++;
        }
    }
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
    deleteGame(findGame(sender, receiver));

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
        if(!instance) {
            instance = new ServerGames();
        }
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
    delete((twoClients*)args);
    return NULL;
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
            return it;
        }
        it++;
    }
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
void ServerGames::deleteAllGames() {
    vector<Room>::iterator it = gamesList.begin();
    int i, size =(int) gamesList.size();
    pthread_mutex_trylock(&mutexCommand);
    for(i = 0; i < size; i ++) {
        string name = it->getRoomName();
        it++;
        if(isGameInList(name)) {
            deleteGame(name);
        }
    }
    pthread_mutex_unlock(&mutexCommand);

}

vector<Room>* ServerGames::getGameList() {
    return &gamesList;
}