//
// Created by ofirhelerman on 1/24/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_FUNCTOR_H
#define ADVANCEDPROGRAMMINGR_O_FUNCTOR_H


#include <netinet/in.h>
#include <string>

/**
 * The functor class is responsible for running the commands in a different thread.
 */
class Functor {
private:
    struct sockaddr_in serverSin;           /// socket address
    struct sockaddr_in clientSin;           /// client socket address
    int serverSocket;                       /// socket file descriptor
    int clientSocket;                       /// client socket file descriptor
    bool isFinished;                        /// flag that indicates if the thread is finished

public:
    /**
     * Constructor of the functor class.
     * @param sin the socket address
     * @param clientSin the client socket address
     * @param serverSocket the socket file descriptor
     * @param clientSocket the client socket file descriptor
     */
    Functor(sockaddr_in sin, sockaddr_in clientSin, int serverSocket, int clientSocket);

    /**
     * The operator function that manages the thread operations.
     */
    void operator()();

    /**
     * Setter for the isFinished flag.
     * @param isFinished the new value of the flag
     */
    void setIsFinished(bool isFinished);
};


#endif //ADVANCEDPROGRAMMINGR_O_FUNCTOR_H
