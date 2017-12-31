//
// Created by raz on 12/23/17.
//

#ifndef EX4_ROOM_H
#define EX4_ROOM_H
#include <string>

using namespace std;

class Room {
public:
    /**
     * create a new room
     * @param playerSocket a given player socket
     * @param name a given name of the game
     */
    Room(int playerSocket, const string &name);
    /**
     * thia xunrion get a Room name
     * @return the name of the open roon
     */
    const string &getRoomName() const;
    /**
     * thisa funtion get other player sicket by giving one player
     * @param playerSocket a given player socket 1
     * @return the other player that plays with player one
     */
    int getOtherSocket(int playerSocket);
    /**
     * rgua function connects player 2 to the game
     * @param playerSocket a given player socket to join
     */
    void connectPlayer2(int playerSocket);
    /**
     * this function check if the game is running.
     * @return true if the game is running, false otherwise
     */
    bool isRunning();
    /**
     * this function set a room name
     * @param roomName a given room name
     */
    void setRoomName(const string &roomName);
    /**
     * this function sets plaer socket 1
     * @param socket1 given player socket
     */
    void setSocket1(int socket1);
    /**
     * this function starts a game.
     */
    void startGame();
    /**
     * tgus function sets a thread to a specific game
     * @param pthread a given thread of the game
     */
    void setThread(pthread_t pthread);
    /**
     * this function returns the thread of the game
     * @return the thread of the room
     */
    pthread_t getThread();
    /**
     * this function gets player socket 1
     * @return player socket 1
     */
    int getPlayerSocket1();
    /**
     * this function gers player socker 2
     * @return player socket 2
     */
    int getPlayerSocket2();




private:
    string nameOfRoom;
    int playerSocket1;
    int playerSocket2;
    bool started;
    pthread_t pthread;
};


#endif //EX4_ROOM_H
