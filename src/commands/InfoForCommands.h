//
// Created by raz on 12/23/17.
//

#ifndef EX4_INFOFORCOMMANDS_H
#define EX4_INFOFORCOMMANDS_H

#include <vector>
#include <string>
#include "Room.h"

using namespace std;

struct InfoForCommands {
public:
    void setSocket(int socket);

    void setInformation(const string &information);

    void setRooms(vector<Room*> &rooms);

    int getSocket() const;

    const string &getInformation() const;


    vector<Room*> getRooms() const;


private:
    int socket = 0;
    string information;
    vector<Room*> &rooms;
};



#endif //EX4_INFOFORCOMMANDS_H
