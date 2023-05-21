//
// Created by ofirhelerman on 1/19/23.
//

#include "server/header/commands/SendFileCommand.h"

SendFileCommand::SendFileCommand(DefaultIO *dio, DataProvider *dataProvider, const string &description) {
    _dataProvider = dataProvider;
    _dio = dio;
    _commandDescription = description;
}

void SendFileCommand::execute() {
    if (!_dataProvider->isSetTestFile() || !_dataProvider->isSetUnclassFile()) {
        _dio->write("please upload data.");
        return;
    }
    if (!_dataProvider->isClassifiedFile()) {
        _dio->write("please classify data.");
        return;
    }

    /**
     * command #5
     */

//    cout << _dataProvider->getClassifiedPath() << endl;
    std::fstream file(_dataProvider->getClassifiedPath());
    if (!file.is_open()) {
        _dio->write("Error occurred in server: could not open classified file. Please try again.");
        return;
    }

    _dio->write("ok");
    std::string message = _dio->read();
    if(message == "failed") {
//        _dio->write("Error occurred: could not access entered path. Please try again.");
        return;
    }

    _dio->readFromFile(_dataProvider->getClassifiedPath());
    for (auto &s: _dio->getContent()) {
        _dio->read();
        _dio->write(s);
    }
//    cout << "out of while loop" << endl;
    if (_commandDescription == "display results") {
//        cout << "display results!!!" << endl;
        _dio->write("Done.");
    }
    _dio->read();
    _dio->write("eof");
    _dio->emptyBuffer();

}