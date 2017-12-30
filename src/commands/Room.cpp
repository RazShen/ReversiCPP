//
// Created by raz on 12/23/17.
//

#include "Room.h"

Room::Room(int playerSocket, const string &name) {
    playerSocket1 = playerSocket;
    playerSocket2 = 0;
    nameOfRoom = name;
    this->started = false;
}

const string &Room::getRoomName() const {
    return this->nameOfRoom;
}

int Room::getOtherSocket (int playerSocket) {
    if(playerSocket == playerSocket1)
        return playerSocket2;
    else if(playerSocket == playerSocket2) {
        return this->playerSocket1;
    }
    return 0;
}

bool Room::isRunning() {
    return this->started;
}

void Room::setRoomName(const string &roomName) {
    this->nameOfRoom = roomName;
}

void Room::setSocket1(int socket1) {
    this->playerSocket1 = socket1;
}

void Room::startGame() {
    //initialise player
    this->started = true;
}

void Room::connectPlayer2(int playerSocket) {
    this->playerSocket2 = playerSocket;
}

void Room::setThread(pthread_t pthread1) {
    pthread = pthread1;
}

pthread_t Room::getThread() {
    return pthread;
}

int Room::getPlayerSocket1() {
    return this->playerSocket1;
}

int Room::getPlayerSocket2() {
    return this->playerSocket2;
}

