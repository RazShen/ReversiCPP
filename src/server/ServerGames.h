//
// Created by tomer on 12/25/17.
//

#ifndef EX4_SERVERGAMES_H
#define EX4_SERVERGAMES_H

#include <vector>
#include "../commands/Room.h"

class ServerGames {
private:
    vector<Room> gamesList;
public:
    ServerGames();
    Room* getGame(string gameName);
    void deleteGame(string gameName);
    void addGame(string gameName, int clientSocket);
    bool isGameInList(string gameName);
    void joinToGame(string gameName, int clientSocket);
    void sendListGames(int clientSocket);
    int size();

};


#endif //EX4_SERVERGAMES_H
