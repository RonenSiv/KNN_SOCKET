//
// Created by ronen on 1/15/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTALGORITHMCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTALGORITHMCOMMAND_H


#include "app/header/Command.h"
#include "client/header/TCP/TCPClient.h"

/**
 * This class is responsible for the client algorithm command.
 */
class ClientAlgorithmCommand : public Command {
private:
    TCPClient *_client{};         /// client object
public:
    /**
     * client algorithm command constructor.
     */
    ClientAlgorithmCommand();

    /**
     * client algorithm command constructor.
     * @param dio
     * @param client
     */
    explicit ClientAlgorithmCommand(DefaultIO *dio, TCPClient *client);

    /**
     * client algorithm exucute function.
     * it overrides the execute function of the command class.
     */
    void execute() override;

    /**
     * client algorithm set client function.
     * @param TCPClient* pClient
     */
    void setClient(TCPClient *pClient);
};

#endif //ADVANCEDPROGRAMMINGR_O_CLIENTALGORITHMCOMMAND_H
