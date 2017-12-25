//
// Created by tomer on 12/25/17.
//
#include <cstring>
#include <iostream>
#include "ServerGames.h"

ServerGames::ServerGames() {}

Room* ServerGames::getGame(string gameName) {

    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (gameName == it->getRoomName()) {
            return &(*it);
        }
    }
    return &(*it);
}

void ServerGames::addGame(string gameName, int clientSocket) {
    if (!isGameInList(gameName)) {
    Room *gameRoom = new Room(clientSocket, gameName);
    gamesList.push_back(*gameRoom);
    }
}

void ServerGames::deleteGame(string gameName) {
    //delete thread.
    //earse from game list
    // delete room (after new)
    Room* roomToDelete = getGame(gameName);
    if(isGameInList(gameName)) {
        delete(roomToDelete);
    }

}

void ServerGames::joinToGame(string gameName, int clientSocket) {
    if(isGameInList(gameName)) {
        Room *roomToJoin = getGame(gameName);
        roomToJoin->connectPlayer2(clientSocket);
        roomToJoin->startGame();
    }
}

string ServerGames::sendListGames(int clientSocket) {
    string list = "The available games are: ";
    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end() && !it->isRunning()) {
        list += it->getRoomName() + " ";
    }
    return list;
}

int ServerGames::size() {
    return (int) gamesList.size();
}

bool ServerGames::isGameInList(string gameName) {

    vector<Room>::iterator it = gamesList.begin();
    while (it != gamesList.end()) {
        if (gameName == it->getRoomName()) return true;
        it++;
    }
    return false;
}
