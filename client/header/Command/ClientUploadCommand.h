#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTUPLOADCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTUPLOADCOMMAND_H


#include "app/header/Command.h"
#include "client/header/TCP/TCPClient.h"
/**
 * This class is responsible for the upload command.
 */
class ClientUploadCommand : public Command {
private:
    TCPClient *_client{};            /// client

public:
    /*
     * Constructor of the class.
     */
    ClientUploadCommand();
    /*
     * Constructor of the class.
     * @param dio the default IO.
     * @param client the client.
     */
    explicit ClientUploadCommand(DefaultIO *dio, TCPClient *client);

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


#endif //ADVANCEDPROGRAMMINGR_O_CLIENTUPLOADCOMMAND_H
