/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */

#define MAXLINE 20
#include <iostream>
#include "Player.h"
#include <fstream>
#include <cstring>
#include <vector>

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


void Player::connectToServer(Display* display) {

}


int Player::getMoveFromServer() {

}

void Player::update(int arg1, int arg2) {
}

void Player::noMove(Display *display) {

}


Player::Player(const char *filename) {
    int serverPort1;
    char portBuf[MAXLINE];
    string buffer;
    char ip[MAXLINE];
    char address[MAXLINE];
    ifstream settings;
    settings.open(filename);
    //const char * buffer2;
    if (!settings) {
        throw "Can't open file, aborting";
    }
//    while (!settings.eof()) {
//        if (buffer == "IP") {
//            settings >> buffer; // buffer is now :
//            settings >> buffer; // buffer equals the ip number
//            //buffer2 = buffer.c_str();
//            writable = new char[buffer.size() + 1];
//            copy(buffer.begin(), buffer.end(), writable);
//            writable[buffer.size()] = '\0';
//        }
//        settings >> buffer;
//        if (buffer == "Port") {
//            settings >> buffer; // buffer is now :
//            settings >> buffer; // buffer is now the port number
//            this->serverPort = atoi(buffer.c_str());
//        }
//    }
    getline(settings,buffer);
    sscanf(buffer.c_str(), "%s : %s", ip , address);
    if (!strcmp(ip, "IP")) {
        this->serverIP = address;
    } else {
        settings.close();
        throw "cannot parse IP";
    }
    getline(settings,buffer);
    sscanf(buffer.c_str(), "%s : %d", portBuf , &serverPort1);
    if (!strcmp(portBuf, "Port")) {
        this->serverPort = serverPort1;
    } else {
        settings.close();
        throw "cannot parse Port";
    }


    settings.close();
    //this->serverIP = writable;
}

int Player::getClientSocket() {
    return this->clientSocket;
}

void Player::setClientSocket(int socket) {
    this->clientSocket = socket;
}

void Player::finishGame() {

}

Player::~Player() {

}

vector<string> Player::parseStringBySpace(string str) {
    vector<string>result;
    string parser = " ";
    while(str.size()){
        unsigned long index = str.find(parser);
        if(index!= string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+parser.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}
