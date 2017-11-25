/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#include "Player.h"


using namespace std;

Player::Player(Board::Status stat) {
    this->type = stat;
}

Board::Status Player::getType() const {
    return this->type;
}

Player::Player() {}



