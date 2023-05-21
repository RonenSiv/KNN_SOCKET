#include "client/header/Command/ClientCommandFactory.h"

Command *ClientCommandFactory::createCommand(int commandNumber, DefaultIO *dio, TCPClient *client) {
    switch (commandNumber) {
        case 1:
            return new ClientUploadCommand(dio, client);
        case 2:
            return new ClientAlgorithmCommand(dio, client);
        case 3:
            return new ClientClassifyCommand(dio, client);
        case 4:
            return new ClientDisplayCommand(dio, client);
        case 5:
            return new ClientDownloadCommand(dio, client);
        case 8:
            return new ClientExitCommand(dio, client);
        default:
            throw std::runtime_error("Invalid command number");
    }
}
