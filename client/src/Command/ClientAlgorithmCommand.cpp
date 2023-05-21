
#include "client/header/Command/ClientAlgorithmCommand.h"

void ClientAlgorithmCommand::execute() {
    _dio->write(_client->Receive());
    std::string line = _dio->read();
    _client->Send(line.empty() ? "keep" : line);
    if (line.empty()) {
        _dio->emptyBuffer();
        return;
    }
    std::string msg = _client->Receive();
    if (msg.find("invalid") != std::string::npos) {
        _dio->write(msg);
    }
    _dio->emptyBuffer();
}

ClientAlgorithmCommand::ClientAlgorithmCommand() {
    ClientAlgorithmCommand::setCommandDescription("algorithm settings");
}

ClientAlgorithmCommand::ClientAlgorithmCommand(DefaultIO *dio, TCPClient *client) {
    ClientAlgorithmCommand::setCommandDescription("algorithm settings");
    ClientAlgorithmCommand::setDio(dio);
    ClientAlgorithmCommand::setClient(client);
}

void ClientAlgorithmCommand::setClient(TCPClient *pClient) {
    _client = pClient;
}


