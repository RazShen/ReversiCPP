/*
 * Tomer Grady 205660863
 * Raz Shenkman 311130777
 */


#ifndef EX3WITHTESTS_PLAYER_H
#define EX3WITHTESTS_PLAYER_H


#include <vector>
#include "Pair.h"
#include "Board.h"
#include "GameLogic.h"

/**
 * This class features a general player.
 */
class Player {
public:

    /**
     * Constructor for the player (from status)
     * @param stat: wanted status.
     */
    Player(Board::Status status);

    /**
     * Empty constructor for the player.
     */
    Player();
    /**
     * constractor to a remote player
     * @param filename a given file
     */
    Player(const char* filename);
    /**
     * constractor for a remote player
     * @param serverIP a given server ip
     * @param serverPort a given server port
     */
    Player(const char *serverIP, int serverPort);

    /**
     * This method return the wanted move the player decided.
     * @param b board.
     * @param positions possible positions
     * @param moves number of positions
     * @return wanted move
     */
    virtual const Pair
    getMove(Pair positions[], int moves, GameLogic *gl, Board::Status opponentStat, Display *display) = 0;
    /**
     * virtual function for a remote player
     */
    virtual void connectToServer(Display* display);
    /**
     * this method updates thr player move
     * @param arg1 a given num
     * @param arg2 a sec given num
     */
    virtual void update(int arg1, int arg2);
    /**
     * this method gets move from the sever
     * @return the given number from the server
     */
    virtual int getMoveFromServer();
    /**
     * this method update when there is no move for the player
     * @param display
     */
    virtual void noMove(Display* display);

    /**
     * This method returns the player's type.
     * @return
     */
    Board::Status getType() const;
    /**
     * this method gets the type of the player
     * @param stat type of the player
     */
    void setType(Board::Status stat);
    /**
     * Getting client socket
     * @return getting client socket
     */
    int getClientSocket();
    /**
     * Setting client socket
     */
    void setClientSocket(int socket);
    /**
     * finish game method
     */
    virtual void finishGame();
    vector<string> parseStringBySpace(string str);
    /**
     * Destructor for player.
     */
    virtual ~Player();
protected:
    Board::Status type;
    string serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX3WITHTESTS_PLAYER_H
