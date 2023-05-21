//
// Created by ofirhelerman on 1/19/23.
//


#include "server/header/commands/UploadCommand.h"

UploadCommand::UploadCommand(DefaultIO *dio, DataProvider *dataProvider) {
    this->_dio = dio;
    this->_dataProvider = dataProvider;
    this->_commandDescription = "upload an unclassified csv file";
}

//void print(std::vector<double> const &input) {
//
//    for (int i = 0; i < input.size(); i++) {
//        std::cout << input.at(i) << ' ';
//    }
//
//    cout << ", size: " << input.size() << " , ";
//}


void UploadCommand::execute() {
    // may cause bugs in creating db, and the try/catch wil detect it as client error
    /**
         * first file train file
         */
    _dataProvider->resetTestFile();
    _dataProvider->resetUnclassFile();
    _dataProvider->resetClassifiedFile();

    _dio->write("Please upload your local train CSV file.");

    // set the message size
    std::string message;
    try {
        // read the file
        message = _dio->read();
        if (message == "failed") {
            _dio->write("invalid input");
            return;
        }

        _dio->setMessageSize(std::stoi(message));
    } catch (...) {
        _dio->write("invalid input");
        return;
    }

    std::string fileName;
    // add ip address of client to avoid conflicts
    fileName = std::to_string(_dataProvider->getClientSocket()) + "_train.csv";
    std::ofstream trainFile(fileName);
    if (!trainFile.is_open()) {
        _dio->write("invalid input");
        return;
    }
    _dio->write("sendFile");
    message = _dio->read();
    while (message != "EOF") {
        trainFile << message;
        message = _dio->read();
        _dio->write("sentFile");
    }
    trainFile.close();
    DataBase<double> *dbTrain = new DataBase<double>(fileName);
    _dataProvider->setTestFile(dbTrain);

    /**
     * for debugging
     */
//    for (auto &v: *dbTrain) {
//        print(v.first);
//        cout << " " << v.second << endl;
//    }
//    cout << "test file indicator in data provider: " << _dataProvider->isSetTestFile() << endl;
    /**
     * end debugging
     */
//                cout << "inside else" << endl;

    _dio->write("Upload complete.\nPlease upload your local test CSV file.");
    string msg = _dio->read();
    while (msg != "sentSize") {
        if (msg == "failed") {
            _dio->write("invalid input");
            remove(fileName.c_str());
            _dataProvider->resetTestFile();
            return;
        }
        msg = _dio->read();
    }
    // set the message size

    try {
        // read the file
        message = _dio->read();
        if (message == "failed") {
            _dio->write("invalid input");
            _dataProvider->resetTestFile();
            return;
        }
        _dio->setMessageSize(std::stoi(message));
    } catch (...) {
        _dio->write("invalid input");
        _dataProvider->resetTestFile();
        return;
    }
    _dio->write("sendFile");
    msg = _dio->read();
    while (msg != "sentFile") {
        msg = _dio->read();
    }
    // read the file
    std::string message2 = _dio->read();
    fileName = std::to_string(_dataProvider->getClientSocket()) + "_test.csv";
    std::ofstream outfile(fileName);
    if (!outfile.is_open()) {
        _dio->write("invalid input");
        _dataProvider->resetTestFile();
        return;
    }
    while (message2 != "EOF") {
        outfile << message2;
        _dio->write("sentFile");
        message2 = _dio->read();
    }
    outfile.close();
//    cout << "line 137" << endl;

    /**
     * second file test file
     */
    DataBase<double> *db = new DataBase<double>(fileName, false);
    _dataProvider->setUnclassFile(db);
//    for (auto &v: *db) {
//        print(v.first);
//        cout << " "<< v.second << endl;
//    }
//    cout << "test file indicator in data provider: " << _dataProvider->isSetTestFile() << endl;
    /**
     * end debugging
     */

    _dio->write("Upload complete.\n");
    _dio->setMessageSize(4096);

}