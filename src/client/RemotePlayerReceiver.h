//
// Created by tomer on 12/2/17.
//

#ifndef EX4_REMOTEPLAYERRECEIVER_H
#define EX4_REMOTEPLAYERRECEIVER_H


#include "../Player.h"

class RemotePlayerReceiver: public Player {
public:
 //   RemotePlayerReceiver(const char *serverIP, int serverPort);
    RemotePlayerReceiver(const char* filename);

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
    int getMoveFromServer();
    void noMove(Display* display);

};


#endif //EX4_REMOTEPLAYERRECEIVER_H
