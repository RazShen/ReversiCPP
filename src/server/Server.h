/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_SERVER_H
#define EX3WITHTESTS_SERVER_H


#include <vector>
#include "ServerGames.h"
#include "../commands/CommandManager.h"


class Server {
public:
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
    static void *handleAccept(void *tempArgs);
    void handleBeforeClient(int clientSocket);


private:
    int port;
    int serverSocket;
    ServerGames* serverGames;
    vector<pthread_t> connectionThreads;


    /**
     * this method handles 2 clients and transfer their massages through function transferMassage
     * @param clientSocket1 a first client socket 
     * @param clientSocket2 a second client socket
     */
    void handleClients(int clientSocket1, int clientSocket2);

    /**
     * this method initializes player and send him a number to read
     * @param playerSocket a given player socket
     * @param playerNum a number to send
     */
    void initializingPlayer(int playerSocket, int playerNum);

    /**
     * this method transfer a massage between 2 players 
     * @param sender a given player that send a massage
     * @param receiver a given player that get the massage from the sender
     * @return if it works, false otherwise
     */
    bool transferMessage(int sender, int receiver);
    void* handleClientHelper(void *tempArgs);
    string readFromClient(int clientSocket);


    };


#endif //EX3WITHTESTS_SERVER_H
