/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include <iostream>
#include "Player.h"


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

int Player::sendMove(int arg1, int arg2) {

}

int Player::getMoveFromServer() {

}
