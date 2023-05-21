
#include "client/header/TCP/TCPClient.h"

TCPClient::TCPClient(const std::string &address, int port) {
    std::string valid = check_client_creation_validity(address, port);
    if (valid != "valid") {
        throw "invalid";

    }

    if ((this->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        throw "problem with creating socket";
    }
    memset(&server_addr, 0, sizeof(server_addr));
    this->address = address;
    this->port = port;
    this->server_addr.sin_family = AF_INET;
    this->server_addr.sin_port = htons(port);
    this->server_addr.sin_addr.s_addr = inet_addr(address.c_str());
}

bool TCPClient::Connect() {
    if (connect(this->sockfd, (struct sockaddr *) &this->server_addr, sizeof(this->server_addr)) < 0) {
        perror("Connection to the server failed!");
        return false;
    }
    return true;
}

bool TCPClient::Send(const std::string &data) const {
    if (send(this->sockfd, data.c_str(), data.size(), 0) < 0) {
        perror("Send failed!");
        return false;
    }
    return true;
}

std::string TCPClient::Receive(int size) const {
    char buffer[size];
    std::string reply;
    ssize_t bytesReceived = recv(this->sockfd, buffer, sizeof(buffer), 0);
    if (bytesReceived < 0)
        return "";
    else {
        buffer[bytesReceived] = '\0';
        reply = buffer;
        return reply;
    }
}

std::string TCPClient::check_client_creation_validity(const std::string &address, int port) {
    struct in_addr ip_addr{};
    const char *ip_string = address.c_str();
    if (inet_pton(AF_INET, ip_string, &ip_addr) != 1) {
        return "Invalid IP address format.";
    }

    if (port < 0 || port > 65535) {
        return "Invalid port number. Port must be between 0 and 65535.";
    }
    return "valid";
}

bool TCPClient::Disconnect() const {
    close(this->sockfd);
    return true;
}

bool TCPClient::IsConnected() const {
    int error = 0;
    socklen_t len = sizeof(error);
    int retval = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len);
    if (retval != 0) {
        return false;
    }
    if (error != 0) {
        return false;
    }
    return true;
}

bool TCPClient::CheckServerStatus() const {
    char buffer[1];
    int n = recv(sockfd, buffer, 1, MSG_PEEK | MSG_DONTWAIT);
    if (n == 0) {
        Disconnect();
        std::cout << "Server closed the connection" << std::endl;
    }
    return n != 0;
}
