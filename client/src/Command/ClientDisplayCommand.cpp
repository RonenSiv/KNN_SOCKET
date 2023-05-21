
#include "client/header/Command/ClientDisplayCommand.h"

void ClientDisplayCommand::execute() {
    std::string line = _client->Receive();
    if (line.find("please") != std::string::npos || line.find("Error") != std::string::npos) {
        _dio->write(line);
        _dio->emptyBuffer();
        return;
    }
    _client->Send("ok");
    while (line != "eof") {
        _client->Send("ok");
        if (line == "ok") {
            line = _client->Receive();
            continue;
        }
        _dio->write(line);
        if (line == "eof")
            break;

        line = _client->Receive();
    }
    _dio->read();
    _dio->emptyBuffer();
}

ClientDisplayCommand::ClientDisplayCommand() {
    ClientDisplayCommand::setCommandDescription("display results");
}

ClientDisplayCommand::ClientDisplayCommand(DefaultIO *dio, TCPClient *client) {
    ClientDisplayCommand::setCommandDescription("display results");
    ClientDisplayCommand::setDio(dio);
    ClientDisplayCommand::setClient(client);
}

void ClientDisplayCommand::setClient(TCPClient *pClient) {
    _client = pClient;
}