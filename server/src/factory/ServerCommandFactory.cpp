//
// Created by ofirhelerman on 1/23/23.
//

#include "server/header/factory/ServerCommandFactory.h"
#include "server/header/commands/UploadCommand.h"
#include "server/header/commands/ExitCommand.h"
#include "server/header/commands/AlgoSetCommand.h"
#include "server/header/commands/ClassifyDataCommand.h"
#include "server/header/commands/SendFileCommand.h"

ServerCommandFactory::ServerCommandFactory(DefaultIO *dio, DataProvider *dataProvider, Functor *functor) {
    this->_dio = dio;
    this->_dataProvider = dataProvider;

//    if (functor != nullptr) {
//        cout << "server is not null from factory" << endl;
//    } else {
//        cout << "server is null from factory" << endl;
//    }
    this->_functor = functor;
}

Command *ServerCommandFactory::createCommand(int commandId) {
    switch (commandId) {
        case 1:
            return new UploadCommand(_dio, _dataProvider);
        case 2:
            return new AlgoSetCommand(_dio, _dataProvider);
        case 3:
            return new ClassifyDataCommand(_dio, _dataProvider);
        case 4:
            return new SendFileCommand(_dio, _dataProvider, "display results");
        case 5:
            return new SendFileCommand(_dio, _dataProvider, "download results");
        case 8:
            return new ExitCommand(_dio, _dataProvider, _functor);
        default:
            return nullptr;
    }
}