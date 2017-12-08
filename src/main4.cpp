//
// Created by raz on 12/8/17.
//

#include <cstdlib>
#include <iostream>
#include "Player.h"
#include <string.h>
#include <fstream>
#include <cstdlib>

int main() {
    const char* serverIP;
    int serverPort;
    string buffer;
    ifstream settings;
    settings.open("sconfig.txt");

   if(settings.fail()) {
        throw "Can't open file, aborting";
    }
    while (!settings.eof()) {
        settings >> buffer;
        if(buffer == "IP"){
            settings>>buffer; // buffer is now :
            settings>>buffer; // buffer equals the port
            serverIP = buffer.c_str();
        } else if (buffer == "Port") {
            settings >> buffer; // buffer = "="
            settings >> buffer; // buffer equals the IP
            serverPort = atoi(buffer.c_str());
        }
        cout <<serverPort<<endl;
        cout<<serverIP<<endl;
    }
    settings.close();
}