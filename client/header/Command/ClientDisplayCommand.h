//
// Created by ronen on 1/15/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTDISPLAYCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTDISPLAYCOMMAND_H


#include "app/header/Command.h"
#include "client/header/TCP/TCPClient.h"

/**
 * This class is responsible for the client display command.
 */
class ClientDisplayCommand : public Command {
private:
    TCPClient *_client{};           /// client object
public:
    /**
     * client display command constructor.
     */
    ClientDisplayCommand();

    /**
     * client display command constructor.
     * @param dio
     * @param client
     */
    explicit ClientDisplayCommand(DefaultIO *dio, TCPClient *client);

    /**
     * client display exucute function.
     * it overrides the execute function of the command class.
     */
    void execute() override;

    /**
     * client display set client function.
     * @param TCPClient* pClient
     */
    void setClient(TCPClient *pClient);
};


#endif //ADVANCEDPROGRAMMINGR_O_CLIENTDISPLAYCOMMAND_H
