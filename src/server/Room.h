//
// Created by raz on 12/23/17.
//

#ifndef EX4_ROOM_H
#define EX4_ROOM_H
#include <string>

using namespace std;

class Room {
public:
    Room(int playerSocket, const string &name);
    const string &getRoomName() const;

    int getOtherSocket(int playerSocket);

    void connectPlayer2(int playerSocket);

    bool isRunning();

    void setRoomName(const string &roomName);

    void setSocket1(int socket1);

    void startGame();

    void setThread(pthread_t pthread);

    pthread_t getThread();
    int getPlayerSocket1();
    int getPlayerSocket2();



private:
    string nameOfRoom;
    int playerSocket1;
    int playerSocket2;
    bool started;
    pthread_t pthread;
};


#endif //EX4_ROOM_H
