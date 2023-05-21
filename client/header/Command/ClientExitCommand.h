//
// Created by ronen on 1/15/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTEXITCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTEXITCOMMAND_H


#include "app/header/Command.h"
#include "client/header/TCP/TCPClient.h"

/**
 * client exit command class.
 */
class ClientExitCommand : public Command {
private:
    TCPClient *_client{};       /// client object
public:
    /**
     * client exit command constructor.
     */
    ClientExitCommand();

    /**
     * client exit command constructor.
     * @param dio
     * @param client
     */
    explicit ClientExitCommand(DefaultIO *dio, TCPClient *client);
    /**
     * client exit exucute function.
     * it overrides the execute function of the command class.
     */
    void execute() override;
    /**
     * client exit set client function.
     * @param TCPClient* pClient
     */
    void setClient(TCPClient *pClient);
};


#endif //ADVANCEDPROGRAMMINGR_O_CLIENTEXITCOMMAND_H
