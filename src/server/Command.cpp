//
// Created by raz on 12/25/17.
//

#include <string.h>
#include "Command.h"

void Command::writeToClient(string inputForClient, int clientSocket) {
    int stringLength = inputForClient.length();
    int n;
    n = (int) write(clientSocket, &stringLength, sizeof(int));
    if (n == -1)
        throw "Error writing string length";
    for (int i = 0; i < stringLength; i++) {
        n = (int) write(clientSocket, &inputForClient[i], sizeof(char));
        if (n == -1)
            throw "Error writing";
    }
}