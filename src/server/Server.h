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
    int calc(int arg1, const char op, int arg2) const;
    void initializingPlayer(int playerSocket, int playerNum);
    bool transferMessege(int sender, int reciever);
    };



#endif //EX3WITHTESTS_SERVER_H
