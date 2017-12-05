//
// Created by tomer on 12/2/17.
//

#ifndef EX4_REMOTEPLAYERCLIENT_H
#define EX4_REMOTEPLAYERCLIENT_H


#include "../Player.h"

class RemotePlayerC: public Player {
public:
    RemotePlayerC(const char *serverIP, int serverPort);
    void connectToServer();
    int sendMove(int arg1, int arg2);
    /**
    * Constructor for the human player.
    */
    RemotePlayerC(Board::Status);
    /**
    * This method asks the user to pick he's selected move.
    * @param positions possible moves.
    * @param moves number of positions.
    * @param gl game logic.
    * @param opponentStat color of the opponent.
    * @param display display.
    * @return user's decided move.
    */
    const Pair getMove(Pair positions[], int moves, GameLogic* gl, Board::Status opponentStat, Display* display);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX4_REMOTEPLAYERCLIENT_H
