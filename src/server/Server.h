//
// Created by raz on 12/2/17.
//

#ifndef EX3WITHTESTS_SERVER_H
#define EX3WITHTESTS_SERVER_H


class Server {
public:
    enum GameStatus {
        InProgress, EndGame
    };
    Server(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClients(int clientSocket1, int clientSocket2);
    void initializingPlayer(int playerSocket, int playerNum);
    bool transferMessage(int sender, int reciever);
    };



#endif //EX3WITHTESTS_SERVER_H
