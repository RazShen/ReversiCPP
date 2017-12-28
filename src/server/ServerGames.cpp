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

ServerGames::ServerGames() {}

vector<Room>::iterator ServerGames::getGame(string gameName) {
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (gameName == it->getRoomName()) {
            return it;
        }
    }
    return it;
}

void ServerGames::addGame(string gameName, int clientSocket) {
    if (!isGameInList(gameName)) {
    Room *gameRoom = new Room(clientSocket, gameName);
    gamesList.push_back(*gameRoom);
    initializingPlayer(clientSocket, 1);
    }
}

void ServerGames::deleteGame(string gameName) {
    //delete thread.
    //earse from game list
    // delete room (after new)
    Room roomToDelete = *getGame(gameName);
    if(isGameInList(gameName)) {
        delete(&roomToDelete);
    }
}

void ServerGames::joinToGame(string gameName, int clientSocket2) {
    if(isGameInList(gameName) && !getGame(gameName)->isRunning()) {
        Room roomToJoin = *getGame(gameName);
        roomToJoin.connectPlayer2(clientSocket2);
        initializingPlayer(clientSocket2, 2);
        initializingPlayer(roomToJoin.getOtherSocket(clientSocket2), 3);
        roomToJoin.startGame();
        this->handleClients(roomToJoin.getOtherSocket(clientSocket2), clientSocket2);
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
    string list = "The available games are: ";
    if (this->gamesList.empty()) {
        list = "No available games to join.";
        return list;
    }
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end() && !it->isRunning()) {
        cout << it->getRoomName() << endl;
        list += it->getRoomName() + " ";
        it++;
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
            if (gameName == it->getRoomName()) return true;
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
    if (instance == 0)
    {
        instance = new ServerGames;
    }
    return instance;
}

ServerGames *ServerGames::instance = NULL;


