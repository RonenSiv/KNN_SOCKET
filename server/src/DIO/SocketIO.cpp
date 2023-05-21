//
// Created by ofirhelerman on 1/21/23.
//

#include "server/header/DIO/SocketIO.h"


SocketIO::SocketIO(DataProvider *dataProvider) {
    _dataProvider = dataProvider;
}

string SocketIO::read() {
    int bufferSize = _messageSize;
    std::vector<char> buffer(bufferSize);
    int numBytesRead = recv(_dataProvider->getClientSocket(), buffer.data(), buffer.size(), 0);
    std::string message;

    if (numBytesRead > 0) {
        message = std::string(buffer.begin(), buffer.begin() + numBytesRead);
    } else if (numBytesRead == 0) {
        message = "Client disconnected";
    } else {
        throw "Error receiving message";
    }
//    cout << "message received: " << message << endl;
    return message;
}

void SocketIO::write(string text) {
    int numBytesSent = send(_dataProvider->getClientSocket(), text.c_str(), text.length(), 0);
    if (numBytesSent < 0) {
        throw "Error sending message";
    }
}

SocketIO::~SocketIO() = default;