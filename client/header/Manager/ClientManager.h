
#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTMANAGER_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTMANAGER_H


#include "client/header/TCP/TCPClient.h"

/*
 * This class is responsible for the client manager.
 */
class ClientManager {
private:
    static ClientManager *_instance;    // The instance of the class
    static TCPClient *_client;          // The client

    /*
     * Constructor of the class - creates a new client manager.
     */
    ClientManager() = default;

    /*
     * Destructor of the class.
     */
    ~ClientManager() = default;

public:
    /*
     * This function is responsible for getting the instance of the class.
     * @param ip the ip address of the server.
     * @param port the port number of the server.
     * @return the instance of the class.
     */
    static ClientManager *getInstance(const std::string &ip, const std::string &port);

    /**
     * This function is responsible for getting the client.
     * @return the client.
     */
    static TCPClient *getClient();

    /**
     * This function is responsible for deleting the instance of the class.
     */
    ClientManager(const ClientManager &) = delete;

    /**
     * This function is responsible for assigning the instance of the class.
     */
    ClientManager &operator=(const ClientManager &) = delete;

};

#endif //ADVANCEDPROGRAMMINGR_O_CLIENTMANAGER_H
