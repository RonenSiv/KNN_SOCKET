//
// Created by ofirhelerman on 1/21/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_EXITCOMMAND_H
#define ADVANCEDPROGRAMMINGR_O_EXITCOMMAND_H




#include "app/header/Command.h"
#include "server/header/util/DataProvider.h"
#include "server/header/util/Functor.h"

class ExitCommand : public Command {
public:
    ExitCommand(DefaultIO *dio, DataProvider *dataProvider, Functor *functor);
    void execute() override;
    ~ExitCommand() = default;

private:
    Functor *functor;
    DataProvider *_dataProvider;
};


#endif //ADVANCEDPROGRAMMINGR_O_EXITCOMMAND_H
