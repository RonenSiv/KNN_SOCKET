//
// Created by ofirhelerman on 1/19/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_SENDFILECOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_SENDFILECOMMAND_H


#include "server/header/DIO/SocketIO.h"
#include "app/header/Command.h"
/**
 * This class represents the command that sends the data to the client
 */
class SendFileCommand : public Command {
public:
    /**
     * Constructor of SendFileCommand
     * @param dio the default io object
     * @param dataProvider a mechanism to share data between commands
     */
    SendFileCommand(DefaultIO *dio, DataProvider *dataProvider, const string &description);
    void execute() override;
    ~SendFileCommand() = default;


private:
    DataProvider *_dataProvider; /// Pointer to the data provider
};

#endif //ADVANCEDPROGRAMMINGR_O_SENDFILECOMMAND_H
