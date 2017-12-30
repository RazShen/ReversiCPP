/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_SERVER_H
#define EX3WITHTESTS_SERVER_H


#include <vector>
#include "ServerGames.h"
#include "CommandManager.h"


class Server {
public:
    struct serverAndClient {
    private:
        Server* server;
        int clientS;
    public:
        serverAndClient(Server* s, int client) {
            server = s;
            clientS = client;
        }
        int getClientS() {
            return clientS;
        }
        Server* getServer() {
            return server;
        }
    };
    enum GameStatus {
        InProgress, EndGame
    };

    /**
     * Constructor for server.
     * @param port
     */
    Server(int port);

    /**
     * Start the server
     */
    void start();

    /**
     * Stop the server.
     */
    void stop();

    vector<string> parseStringBySpace(string str);
    static void *handleAccept(void *structOfserver);
    void handleBeforeClient(int clientSocket);
    static void *changeShouldStop(void *args);
    void stopServer();

private:
    int port;
    int serverSocket;
    vector<pthread_t> connectionThreads;
    bool shouldStop;
    string readFromClient(int clientSocket);
    };


#endif //EX3WITHTESTS_SERVER_H
