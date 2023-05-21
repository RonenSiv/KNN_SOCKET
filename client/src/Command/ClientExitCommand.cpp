
#include "client/header/Command/ClientExitCommand.h"

void ClientExitCommand::execute() {
    _client->Disconnect();
}

ClientExitCommand::ClientExitCommand() {
    ClientExitCommand::setCommandDescription("exit");
}

ClientExitCommand::ClientExitCommand(DefaultIO *dio, TCPClient *client) {
    ClientExitCommand::setCommandDescription("exit");
    ClientExitCommand::setDio(dio);
    ClientExitCommand::setClient(client);
}

void ClientExitCommand::setClient(TCPClient *pClient) {
    _client = pClient;
}