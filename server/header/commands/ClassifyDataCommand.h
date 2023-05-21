//
// Created by ofirhelerman on 1/19/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_CLASSIFYDATACOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_CLASSIFYDATACOMMAND_H


#include "app/header/Command.h"
#include "server/header/util/DataProvider.h"
/**
 * This class represents the command that classifies the data, using the KNN algorithm
 */
class ClassifyDataCommand : public Command {
public:
    /**
     * Constructor of ClassifyDataCommand
     * @param dio the default io object
     * @param dataProvider a mechanism to share data between commands
     */
    ClassifyDataCommand(DefaultIO *dio, DataProvider *dataProvider);
    void execute() override;
    ~ClassifyDataCommand() = default;


private:
    DataProvider *_dataProvider;
};
#endif //ADVANCEDPROGRAMMINGR_O_CLASSIFYDATACOMMAND_H
