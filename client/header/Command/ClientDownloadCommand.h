//
// Created by ronen on 1/15/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTDOWNLOADCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTDOWNLOADCOMMAND_H


#include "app/header/Command.h"
#include "client/header/TCP/TCPClient.h"
#include <thread>

/**
 * This class is responsible for the client download command.
 */
class ClientDownloadCommand : public Command{
private:
    TCPClient *_client{};        /// client object

public:
    /**
     * client download command constructor.
     */
    ClientDownloadCommand();

    /**
     * client download command constructor.
     * @param dio
     * @param client
     */
    explicit ClientDownloadCommand(DefaultIO *dio, TCPClient *client);

    /**
     * client download exucute function.
     * it overrides the execute function of the command class.
     */
    void execute() override;

    /**
     * client download set client function.
     * @param TCPClient* pClient
     */
    void setClient(TCPClient *pClient);
};


#endif //ADVANCEDPROGRAMMINGR_O_CLIENTDOWNLOADCOMMAND_H
