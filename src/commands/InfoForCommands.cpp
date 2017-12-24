//
// Created by raz on 12/23/17.
//

#include "InfoForCommands.h"

void InfoForCommands::setSocket(int socket) {
    this->socket = socket;
}

void InfoForCommands::setInformation(const string &information) {
    this->information = information;
}

int InfoForCommands::getSocket() const {
    return this->socket;
}

const string &InfoForCommands::getInformation() const {
    return this->information;
}

vector &InfoForCommands::getRooms() const {
    return this->rooms;
}

void InfoForCommands::setRooms(vector &rooms) {
    this->rooms = rooms;
}

