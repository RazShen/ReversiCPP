//ID: 311130777
//Name: Raz Shenkman
/*
 * HumanPlayer.cpp
 *  This struct features a human player.
 *  Created on: Nov 2, 2017
 *      Author: Raz Shenkman
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



