/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <iostream>
#include "Player.h"
#include <fstream>
#include <cstdlib>

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

    if(!settings) {
        cout <<1;
        throw "Can't open file, aborting";
    }
    cout<<1;
    while (!settings.eof()) {
        settings >> buffer;
        if(buffer == "IP"){
            settings>>buffer; // buffer is now :
            settings>>buffer; // buffer equals the port
            this->serverIP = buffer.c_str();
        } else if (buffer == "Port") {
            settings >> buffer; // buffer = "="
            settings >> buffer; // buffer equals the IP
            this->serverPort = atoi(buffer.c_str());
        }
        cout <<serverPort<<endl;
        cout<<serverIP<<endl;
    }
    settings.close();
}