//
// Created by raz on 12/2/17.
//

#ifndef EX3WITHTESTS_SERVER_H
#define EX3WITHTESTS_SERVER_H


class Server {
public:
    Server(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int clientSocket);
    int calc(int arg1, const char op, int arg2) const;
};


#endif //EX3WITHTESTS_SERVER_H
