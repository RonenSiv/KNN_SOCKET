//
// Created by ofirhelerman on 1/19/23.
//

#include "server/header/commands/AlgoSetCommand.h"
#include "server/header/factory/DistanceFactory.h"


AlgoSetCommand::AlgoSetCommand(DefaultIO *dio, DataProvider *dataProvider) {
    _dio = dio;
    _dataProvider = dataProvider;
    _commandDescription = "algorithm settings";
}


void AlgoSetCommand::execute() {
    std::string message = "The current KNN parameters are: k = " + std::to_string(_dataProvider->getK()) + ",  " +
                          "distance metric = " + _dataProvider->getMetric()->getName();
    _dio->write(message);

    message = _dio->read();
//    cout << " message that the server got from client: " << message << endl;
    if (message == "keep") {
        return;
    }
    string temp;
    string metricName;
    std::string prompt = "";
    stringstream ss(message);
    string kStr;
    bool validInput = true;
    if(message.find_first_of(" \t\n\r") == std::string::npos) {
        prompt = "invalid input to few arguments please enter k and metric\n";
        validInput = false;
        goto end;
    }
    ss >> kStr;
    int k;
//    ss >> std::ws;  // eat whitespace after number
    // check that ss.fail() is the right way to check for invalid input
    try {
        k = std::stoi(kStr);
        if (ss.fail() || k < 1) {
            prompt += "invalid input for K\n";
//        _dio->write(prompt);
            validInput = false;
        }
    } catch (...) {
        validInput = false;
        prompt += "invalid input for K\n";
    }

    ss >> metricName;

    DistanceFactory<double> factory;
    Distance<double> *metric;
    try {
        metric = factory.createDistanceAlgo(metricName);
    } catch (const char *e) {
        prompt += "invalid input for metric\n";
//        _dio->write(prompt);
        validInput = false;
    }

    ss >> temp;
    if(!temp.empty()) {
        prompt = "invalid input to many arguments please enter only k and metric\n";
        validInput = false;
    }
    if (prompt.empty()) {
        prompt = "success\n";
    }
    end:
    _dio->write(prompt);
    if (!validInput) {
        return;
    }
    this->_dataProvider->setK(k);
    this->_dataProvider->setMetric(metric);
}