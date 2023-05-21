//
// Created by ofirhelerman on 1/21/23.
//

#include "server/header/commands/ExitCommand.h"
#include <unistd.h>

ExitCommand::ExitCommand(DefaultIO *dio, DataProvider *dataProvider, Functor *functor) {
    _dio = dio;
    _dataProvider = dataProvider;
    this->functor = functor;
    _commandDescription = "exit";
    int client_socketfd = _dataProvider->getClientSocket();
    basic_string<char, char_traits<char>, allocator<char>> _classifiedPath = to_string(client_socketfd) + "_classified.csv";
    basic_string<char, char_traits<char>, allocator<char>> _testPath = to_string(client_socketfd) + "_test.csv";
    basic_string<char, char_traits<char>, allocator<char>> _trainPath = to_string(client_socketfd) + "_train.csv";
    remove(_classifiedPath.c_str());
    remove(_testPath.c_str());
    remove(_trainPath.c_str());
}

void ExitCommand::execute() {
//    close(_dataProvider->getSockfd()); check that its working
    functor->setIsFinished(true);
    delete (_dataProvider);
}
