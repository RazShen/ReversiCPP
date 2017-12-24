//
// Created by raz on 12/23/17.
//

#ifndef EX4_ROOM_H
#define EX4_ROOM_H
#include <string>

using namespace std;

struct Room {
public:
    const string &getRoomName() const;

    int getSocket1() const;

    int getSocket2() const;

    bool isIsRunning() const;

    void setRoomName(const string &roomName);

    void setSocket1(int socket1);

    void setSocket2(int socket2);

    void setIsRunning(bool isRunning);

private:
    string nameOfRoom;
    int socket1;
    int socket2;
    bool isRunning = false;
};


#endif //EX4_ROOM_H
