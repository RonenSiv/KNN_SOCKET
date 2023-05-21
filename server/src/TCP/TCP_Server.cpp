#include <netdb.h>
#include <fstream>
#include <thread>
#include "app/header/StandardIO.h"
#include "server/header/commands/UploadCommand.h"
#include "server/header/commands/ExitCommand.h"
#include "server/header/TCP/TCP_Server.h"


TCP_Server::TCP_Server() {
    this->shouldExit = false;
}

bool TCP_Server::isValidPort(const string &port) {
    try {
        int portNum = stoi(port);
        if ((portNum < 0) | (portNum > 65535)) {
            std::cerr << "The port number that you've entered in not in the correct range." << endl;
            return 0;
        }
        if (0 <= portNum && portNum <= 49151) {
            struct servent result{};
            char buffer[1024];
            struct servent *service;
            int error = getservbyport_r(htons(portNum), nullptr, &result, buffer,
                                        sizeof(buffer), &service);
            if (error == 0 && service != nullptr) {
                cerr << "Port: " + std::to_string(portNum) + " is reserved for: " + service->s_name << "." << endl;
                return 0;
            }
        }
        this->port = portNum;
        return true;
    } catch (std::invalid_argument &e) {
        std::cerr << "Error: problem with converting the port number." << endl;
        return false;
    }

}

bool TCP_Server::isValidFilePath(const string &filePath) {
    // checking that the path is valid
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error with opening file: please check that you've entered a valid path." << endl;
        return false;
    }
    file.close();
    this->filePath = filePath;
    return true;
}

void TCP_Server::socketAndBindPhase() {

    // initializing the sin struct for telling bind() how to make the bind
    memset(&this->sin, 0, sizeof(this->sin));
    this->sin.sin_family = AF_INET;
    this->sin.sin_addr.s_addr = INADDR_ANY;
    this->sin.sin_port = htons(this->port);

    // creating the socket
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sockfd < 0) {
        throw "error in creating socket";
    }

    // making the bind phase
    if (bind(this->sockfd, (struct sockaddr *) &this->sin, sizeof(this->sin)) < 0) {
        throw "error binding socket";
    }
}


void TCP_Server::listenPhase() const {
    if (listen(this->sockfd, 5) < 0) { // check that 2 in the right backlog number
        throw "error listening to socket\n";
    }
}

int TCP_Server::acceptPhase() {
    unsigned int addressLen = sizeof(this->clientSin);
    int clientSocket = accept(this->sockfd, (struct sockaddr *) &this->clientSin, &addressLen);
    return clientSocket;
}

void TCP_Server::establishChannel() {
    listenPhase();
    acceptPhase();
}


void TCP_Server::setShouldExit(bool shouldExit) {
    this->shouldExit = shouldExit;
}



void TCP_Server::closeChannel() const {
    close(this->sockfd);
}



void TCP_Server::run() {
    /**
     * creating the socket and binding it, establishing the channel
     */
    try {
        socketAndBindPhase();
        listenPhase();
    } catch (const char *msg) {
        string message(msg);
        string error = "Error from server: " + message + ". Please try again later.";
        cerr << error << endl;
        return;
    }
    while (true) {
        int clientSocket = acceptPhase();
        if (clientSocket < 0) {
            cout << "error accepting client\n" << endl;
            continue;
        }
        Functor functor(this->sin, this->clientSin, this->sockfd, clientSocket);
        std::thread t(functor);
        t.detach();
    }
}

