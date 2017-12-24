//
// Created by raz on 12/23/17.
//

#include "Room.h"

const string &Room::getRoomName() const {
    return this->nameOfRoom;
}

int Room::getSocket1() const {
    return this->socket1;
}

int Room::getSocket2() const {
    return this->socket2;
}

bool Room::isIsRunning() const {
    return this->isRunning;
}

void Room::setRoomName(const string &roomName) {
    this->nameOfRoom = roomName;
}

void Room::setSocket1(int socket1) {
    this->socket1 = socket1;
}

void Room::setSocket2(int socket2) {
    this->socket2 = socket2;
}

void Room::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}
