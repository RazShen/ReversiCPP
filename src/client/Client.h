//
// Created by tomer on 12/2/17.
//

#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H


class Client {
public:
    Client(const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
};


#endif //EX4_CLIENT_H
