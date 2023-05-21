//
// Created by ofirhelerman on 1/19/23.
//

#include <cstring>
#include "server/header/commands/ClassifyDataCommand.h"
#include "server/header/database/Classification.h"

ClassifyDataCommand::ClassifyDataCommand(DefaultIO *dio, DataProvider *dataProvider) {
    _dio = dio;
    _dataProvider = dataProvider;
    _commandDescription = "classify data";
}


void ClassifyDataCommand::execute() {
    string message;
    if (!_dataProvider->isSetTestFile() || !_dataProvider->isSetTestFile()) {
        message = "please upload data.";
        _dio->write(message);
        return;
    }
    try {
        int index = 0;
        DataBase<double> trainDB = *_dataProvider->getUnclassFile();
        Distance<double>* metric = _dataProvider->getMetric();
        DataBase<double> testDB = *_dataProvider->getTestFile();
        _dataProvider->setClassifiedPath(std::to_string(_dataProvider->getClientSocket()) + "_classified.csv");
        std::ofstream classified(_dataProvider->getClassifiedPath());
        for (auto &v: trainDB) {
            int k = _dataProvider->getK();
//            cout << "k: " << k << endl;
            string classification = Classification<double>::KNN(k, v.first, testDB, *metric);
//            for (double d: v.first) {
//                cout << d << ",";
//            }
//            cout << endl;
//            cout << "classification: " << classification << endl;
            // might make an error because of the +1 and the endl
            classified << index + 1 << " " << classification << endl;
            // mainly for debugging
            _dataProvider->getUnclassFile()->setType(classification, index);
            index++;
        }
        classified.close();

        ifstream ifs(_dataProvider->getClassifiedPath());
        //for debugging
        string text;

//        while (!ifs.eof()) {
//            getline(ifs, text);
//            cout << "" << text << "\n";
//        }

        message = "classifying data complete";
        _dio->write(message);
        _dataProvider->setClassifiedIndicator(true);
    } catch (const char *e) {
        _dio->write(e);
        // might need to set the classified indicator to false and delete file
    } catch (...) {
        message = "Error in classify data";
        _dio->write(message);
        // might need to set the classified indicator to false and delete file
    }
}