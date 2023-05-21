//
// Created by ofirhelerman on 1/23/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_SERVERCOMMANDFACTORY_H
#define ADVANCEDPROGRAMMINGR_O_SERVERCOMMANDFACTORY_H



#include "app/header/Command.h"
#include "server/header/util/DataProvider.h"
#include "server/header/util/Functor.h"


/**
 * This class is responsible for creating the commands that the server needs to execute.
 * To do so, the class implements the factory design pattern.
 */
class ServerCommandFactory {


private:
    DefaultIO *_dio;                /// The default IO object that is used by the commands.
    DataProvider *_dataProvider;    /// The data provider object that is used by the commands.
    Functor *_functor;              /// The functor object that is used by the commands.

public:

    /**
     * Constructor for the ServerCommandFactory class.
     * @param dio the default IO object that is used by the commands.
     * @param dataProvider the data provider object that is used by the commands.
     * @param functor the functor object that is used by the commands.
     */
    ServerCommandFactory(DefaultIO *dio, DataProvider *dataProvider, Functor *functor);
    ~ServerCommandFactory() = default;
    Command *createCommand(int commandId);
};


#endif //ADVANCEDPROGRAMMINGR_O_SERVERCOMMANDFACTORY_H
