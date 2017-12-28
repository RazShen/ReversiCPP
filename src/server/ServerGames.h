//
// Created by tomer on 12/25/17.
//

#ifndef EX4_SERVERGAMES_H
#define EX4_SERVERGAMES_H

#include <vector>
#include "../commands/Room.h"

class ServerGames {
private:
    static ServerGames *instance;
    ServerGames();
    ServerGames(const ServerGames &other);
    ~ServerGames();

    vector<Room> gamesList;
    void handleClients(int player1, int player2);
    bool transferMessage(int sender, int receiver);

public:
    struct twoClients {
    private:
        ServerGames* sG;
        int client1;
        int client2;
    public:
        twoClients(int c1, int c2, ServerGames* serverGames) {
            client1 = c1;
            client2 = c2;
            sG = serverGames;
        }
        int getClient1() {
            return client1;
        }
        int getClient2() {
            return client2;
        }
        ServerGames* getServerGames() {
            return sG;
        }
    };
    static ServerGames *getInstance();
 //   static void deleteInstance();
    vector<Room>::iterator getGame(string gameName);
    void deleteGame(string gameName);
    void addGame(string gameName, int clientSocket);
    bool isGameInList(string gameName);
    void joinToGame(string gameName, int clientSocket);
    string sendListGames();
    int size();
    void initializingPlayer(int playerSocket, int playerNum);
    bool isGameRunning(string gameName);
    static void* wrapHandleClients(void* args);
};


#endif //EX4_SERVERGAMES_H
