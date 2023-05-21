//
// Created by ofirhelerman on 1/19/23.
//5

#ifndef ADVANCEDPROGRAMMINGR_O_ALGOSETCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_ALGOSETCOMMAND_H


#include "app/header/Command.h"
#include "server/header/util/DataProvider.h"

/**
 * This class represents the command that sets the algorithm to be used and the number of
 * neighbors to be used in the KNN algorithm
 */
class AlgoSetCommand : public Command {
public:
    /**
     * Constructor of AlgoSetCommand
     * @param dio the default io object
     * @param dataProvider a mechanism to share data between commands
     */
    AlgoSetCommand(DefaultIO *dio, DataProvider *dataProvider);
    void execute() override;
    ~AlgoSetCommand() = default;

private:
    DataProvider *_dataProvider;    /// Pointer to the data provider
};
#endif //ADVANCEDPROGRAMMINGR_O_ALGOSETCOMMAND_H
