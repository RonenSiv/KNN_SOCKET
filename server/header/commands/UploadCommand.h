//
// Created by ofirhelerman on 1/19/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_UPLOADCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_UPLOADCOMMAND_H



#include "app/header/Command.h"
#include "server/header/util/DataProvider.h"
/**
 * This class represents the command that uploads the data from the client
 */
class UploadCommand : public Command {
public:
    /**
     * Constructor of UploadCommand
     * @param dio the default io object
     * @param dataProvider a mechanism to share data between commands
     */
    UploadCommand(DefaultIO *dio, DataProvider *dataProvider);
    void execute() override;
    ~UploadCommand() = default;


private:
    DataProvider *_dataProvider;   /// Pointer to the data provider
};

#endif //ADVANCEDPROGRAMMINGR_O_UPLOADCOMMAND_H
