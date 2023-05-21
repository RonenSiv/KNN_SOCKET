#ifndef ADVANCEDPROGRAMMINGR_O_CLIENTCOMMANDFACTORY_H
#define ADVANCEDPROGRAMMINGR_O_CLIENTCOMMANDFACTORY_H


#include "app/header/Command.h"
#include "client/header/Command/ClientUploadCommand.h"
#include "client/header/Command/ClientAlgorithmCommand.h"
#include "client/header/Command/ClientClassifyCommand.h"
#include "client/header/Command/ClientDisplayCommand.h"
#include "client/header/Command/ClientDownloadCommand.h"
#include "client/header/Command/ClientExitCommand.h"

/**
 * This class is responsible for the client command factory.
 */
class ClientCommandFactory {
public:
    /**
     * client command factory constructor.
     */
    ClientCommandFactory() = default;

    /**
     * client command factory create command function. its static so it can be called without an instance.
     * @param commandNumber - the command number
     * @param dio           - the default io object
     * @param client        - the client object
     * @return Command*     - the command object
     */
    static Command* createCommand(int commandNumber, DefaultIO* dio, TCPClient* client);

    /**
     * client command factory destructor.
     */
    ~ClientCommandFactory() = default;
};


#endif //ADVANCEDPROGRAMMINGR_O_CLIENTCOMMANDFACTORY_H
