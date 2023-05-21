//
// Created by ronen on 1/3/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_TCPCLIENT_H
#define ADVANCEDPROGRAMMINGR_O_TCPCLIENT_H

#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

/**
 * TCPClient class
 * This class is used to create a TCP client that can connect to a server and send and receive data.
 * The class is used by creating a new TCPClient object and passing the server's address and port.
 */
class TCPClient {
private:
    int sockfd;                                 /// Socket file descriptor
    std::string address;                        /// Server address
    int port;                                   /// Server port
    struct sockaddr_in server_addr{};           /// Server address struct

public:
    /**
     * TCPClient constructor
     * This constructor creates a new TCPClient object.
     * @param address - The server's address.
     * @param port - The server's port.
     */
    TCPClient(const std::string &address, int port);

    /**
     * Connect function
     * This function connects the client to the server.
     * @return - True if the connection was successful, False otherwise.
     */
    bool Connect();

    /**
     * Send function
     * This function sends data to the server.
     * @param data - The data to send.
     * @return - True if the data was sent successfully, False otherwise.
     */
    bool Send(const std::string &data) const;

    /**
     * Receive function
     * This function receives data from the server.
     * @param size - The size of the data to receive.
     * @return - The data received from the server.
     */
    std::string Receive(int size = 4096) const;

    /**
     * Disconnect function - closes the socket.
     */
    bool Disconnect() const;

    /**
     * Check if the client is connected to the server.
     * @return
     */
    bool IsConnected() const;

    /**
     * Check if the server is still connected.
     * @return
     */
    bool CheckServerStatus() const;

    /**
     * check_client_creation_validity function
     * This function checks if the client was created successfully.
     * @param address - The server's address.
     * @param port - The server's port.
     * @return - "valid" if the client was created successfully, an error message otherwise.
     */
    static std::string check_client_creation_validity(const std::string &address, int port);
};


#endif //ADVANCEDPROGRAMMINGR_O_TCPCLIENT_H
