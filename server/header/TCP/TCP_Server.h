#ifndef ADVANCEDPROGRAMMINGR_O_TCP_SERVER_H
#define ADVANCEDPROGRAMMINGR_O_TCP_SERVER_H

#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "app/header/Command.h"
#include "server/header/util/DataProvider.h"

using namespace std;

/**
 * This class is responsible for the TCP server.
 */

class TCP_Server {
private:
    bool shouldExit;                        /// flag to check if the server should exit
    struct sockaddr_in sin;                 /// socket address
    struct sockaddr_in clientSin;           /// client socket address
    int port;                               /// port number
    int sockfd;                             /// socket file descriptor
    int clientSocket;                       /// client socket file descriptor
    string filePath;                        /// path to the file
    string menu;
    vector<Command *> commands;

    void listenPhase() const;               /// listen phase
    int acceptPhase();                     /// accept phase


public:
    /**
     * Constructor of the class - creates a new TCP server.
     */
    TCP_Server();


    /**
     * Destructor of the class.
     */
    ~TCP_Server() = default;

    /**
     * This function is responsible for checking the validity of a port number to be used by the server.
     * @param port the port number to be checked.
     * @return true if is valid, false otherwise.
     */
    bool isValidPort(const std::string &port);


    /**
     * This function is responsible for checking the validity of a file path to be used by the server.
     * @param filePath the file path to be checked.
     * @return true if is valid, false otherwise.
     */
    bool isValidFilePath(const string &filePath);

    /**
     * socketAndBindPhase
     * This function runs the TCP server.
     */
    void socketAndBindPhase();

    /**
     * establishChannel
     * This function connects the server to the client.
     */
    void establishChannel();

    void setShouldExit(bool shouldExit);

    /**
     * closeChannel
     * This function closes the server.
     */
    void closeChannel() const;

    void run();


};


#endif //ADVANCEDPROGRAMMINGR_O_FUNCTOR_H
