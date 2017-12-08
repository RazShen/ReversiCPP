/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <iostream>
#include "Player.h"
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

Player::Player(Board::Status stat) {
    this->type = stat;
}

Board::Status Player::getType() const {
    return this->type;
}

Player::Player() {}

void Player::setType(Board::Status stat) {
    this->type = stat;
}


Player::Player(const char *serverIP, int serverPort) {

}


void Player::connectToServer() {

}


int Player::getMoveFromServer() {

}

void Player::update(int arg1, int arg2) {
    return;
}

void Player::noMove(Display *display) {

}


Player::Player(const char* filename) {
    string buffer;
    ifstream settings;
    settings.open(filename);
    char * writable;
    //const char * buffer2;
    if(!settings) {
        throw "Can't open file, aborting";
    }
    while (!settings.eof()) {
        if(buffer == "IP") {
            settings >> buffer; // buffer is now :
            settings >> buffer; // buffer equals the ip number
            //buffer2 = buffer.c_str();
            writable = new char[buffer.size() + 1];
            copy(buffer.begin(), buffer.end(), writable);
            writable[buffer.size()] = '\0';

        }
        settings >> buffer;
        if (buffer == "Port") {
            settings >> buffer; // buffer is now :
            settings >> buffer; // buffer is now the port number
            this->serverPort = atoi(buffer.c_str());
        }
    }
    settings.close();
    this->serverIP = writable;
}