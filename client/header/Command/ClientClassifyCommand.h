//
// Created by ronen on 1/15/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTCLASSIFYCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTCLASSIFYCOMMAND_H


#include "app/header/Command.h"
#include "client/header/TCP/TCPClient.h"

/**
 * This class is responsible for the client classify command.
 */
class ClientClassifyCommand : public Command {
private:
    TCPClient *_client{};        /// client object
public:
    /**
     * client classify command constructor.
     */
    ClientClassifyCommand();

    /**
     * client classify command constructor.
     * @param dio
     * @param client
     */
    explicit ClientClassifyCommand(DefaultIO *dio, TCPClient *client);

    /**
     * client classify exucute function.
     * it overrides the execute function of the command class.
     */
    void execute() override;

    /**
     * client classify set client function.
     * @param TCPClient* pClient
     */
    void setClient(TCPClient *pClient);

};


#endif //ADVANCEDPROGRAMMINGR_O_CLIENTCLASSIFYCOMMAND_H
