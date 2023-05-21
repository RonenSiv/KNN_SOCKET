#include "client/header/Command/ClientClassifyCommand.h"

void ClientClassifyCommand::execute() {
    _dio->write(_client->Receive());
}

ClientClassifyCommand::ClientClassifyCommand() {
    ClientClassifyCommand::setCommandDescription("classify data");
}

ClientClassifyCommand::ClientClassifyCommand(DefaultIO *dio, TCPClient *client) {
    ClientClassifyCommand::setCommandDescription("classify data");
    ClientClassifyCommand::setDio(dio);
    ClientClassifyCommand::setClient(client);
}

void ClientClassifyCommand::setClient(TCPClient *pClient) {
    _client = pClient;
}

