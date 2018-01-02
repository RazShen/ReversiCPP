//
// Created by tomer on 12/25/17.
//

#ifndef EX4_SERVERGAMES_H
#define EX4_SERVERGAMES_H

#include <vector>
#include "Room.h"

class ServerGames {
private:
    pthread_mutex_t mutexCommand;
    vector<Room> gamesList;
    static ServerGames *instance;
    ServerGames();
    ServerGames(const ServerGames &other);
    ~ServerGames();
    /**
 * this method handles 2 clients and transfer their massages through function transferMassage
 * @param clientSocket1 a first client socket
 * @param clientSocket2 a second client socket
 */
    void handleClients(int player1, int player2);
    /**
 * this method transfer a massage between 2 players
 * @param sender a given player that send a massage
 * @param receiver a given player that get the massage from the sender
 * @return if it works, false otherwise
 */
    bool transferMessage(int sender, int receiver);
    /**
 * this function returns the iterator of a given game name
 * @param gameName a given name
 * @return iterator of the Room
 */
    vector<Room>::iterator getGameIterator(string gameName);
    /**
    * this function find a game by 2 players socket
    * @param player1 a given player socket 1
    * @param player2 a given player socket 2
    * @return the name of the game the the player plays
    */
    string findGame(int player1, int player2);

    bool hasAtLeastOneRunningGame();
public:
    struct twoClients {
    private:
        ServerGames* sG;
        int client1;
        int client2;
    public:
        /**
         * Struct for running the handle-clients method.
         * @param c1 client1 socket
         * @param c2 client2 socket
         * @param serverGames object that holds all the information about the games.
         */
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
    /**
     * this function find the room from a given name
     * @param gameName a given name of the room
     * @return a pointer to a room
     */
    Room* getGame(string gameName);
    /**
     * this function delete a game
     * @param gameName given name
     */
    void deleteGame(string gameName);
    /**
     * this function creates a game to the gamelist
     * @param gameName a given name
     * @param clientSocket a client socket
     */
    void addGame(string gameName, int clientSocket);
    /**
     * this function checks if the game is in the list
     * @param gameName a given name
     * @return true if the game is in the list
     */
    bool isGameInList(string gameName);
    /**
     *this function join a client to an open game
     * @param gameName a given name
     * @param clientSocket a given client socket
     */
    void joinToGame(string gameName, int clientSocket);
    /**
     * this function returns the list of the available games
     * @return a string represent the list of the available games
     */
    string sendListGames();
    /**
     * this functinon returns the size of the list
     * @return the size of the list
     */
    int size();
    /**
     * this function initialize a player
     * @param playerSocket a given player socket
     * @param playerNum a given num that initialize to the player
     */
    void initializingPlayer(int playerSocket, int playerNum);
    /**
     * this function checks if the game is running
     * @param gameName a given name of a game
     * @return true is the game is running, false otherwise
     */
    bool isGameRunning(string gameName);
    /**
     * this function wraps handle clients function and run it, for a thread
     * @param args a given arguments
     * @return arguments
     */
    static void* wrapHandleClients(void* args);
    /**
     * this function deletes all the games from the list
     */
    void deleteAllGames();
    vector<Room>* getGameList();


};
#endif //EX4_SERVERGAMES_H
