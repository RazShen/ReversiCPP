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
        /**
         * Struct for running the commands
         * @param s the server
         * @param client client socket
         */
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


    void stopServer();

private:
    int port;
    int serverSocket;
    vector<pthread_t> connectionThreads;
    pthread_t threadServer;
    bool shouldStop;
    /**
     * this function read from a client
     * @param clientSocket a given client socket to read from
     * @return string that read from the client
     */
    string readFromClient(int clientSocket);
    /**
 * this function change a string divided by space into vector of strings
 * @param str given string
 * @return vector of strings
 */
    vector<string> parseStringBySpace(string str);
    /**
     * this function handle a client after acceptance to the server
     * @param clientSocket a given client socket
     */
    void handleBeforeClient(int clientSocket);

    /**
     * this function runs handleBeforeClient function
     * @param structOfserver given arguments
     * @return arguments
     */
    static void *handleAccept(void *structOfServer);
    /**
     * this function handle a situation that the user type exit massage to finish the game
     * @param args given arguments
     * @return arguments
     */
    static void *changeShouldStop(void *args);
    /**
     * this function stops the server
     */
};


#endif //EX3WITHTESTS_SERVER_H
