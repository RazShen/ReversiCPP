//
// Created by raz on 12/5/17.
//

#ifndef EX4_REMOTEPLAYERSENDER_H
#define EX4_REMOTEPLAYERSENDER_H


#include "../Board.h"
#include "RemotePlayerReceiver.h"

class RemotePlayerSender: public Player {
public:
//    RemotePlayerSender(const char *serverIP, int serverPort);
    RemotePlayerSender(const char* filename);
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
    void connectToServer();
    void update(int arg1, int arg2);
    int getMoveFromServer();
    void noMove(Display* display);



};


#endif //EX4_REMOTEPLAYERSENDER_H
