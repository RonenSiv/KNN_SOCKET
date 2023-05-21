//
// Created by ofirhelerman on 1/21/23.
//



#include "server/header/util/DataProvider.h"
#include "server/header/distance/EuclideanDistance.h"

DataProvider::DataProvider() {
    this->k = 5;
    this->metric = new EuclideanDistance<double>();
    this->unclassDB = nullptr;
    this->testDB = nullptr;
    this->unclassIndicator = false;
    this->testFileIndicator = false;
    this->classifiedPath = "classified.txt";
    this->isClassified = false;
    this->isExit = false;
}

void DataProvider::setK(int k) {
    this->k = k;
}

void DataProvider::setMetric(Distance<double> *metric) {
    this->metric = metric;
}

void DataProvider::setUnclassFile(DataBase<double> *unclassFile) {
    this->unclassDB = unclassFile;
    this->unclassIndicator = true;
}

void DataProvider::resetUnclassFile() {
    this->unclassDB = nullptr;
    this->unclassIndicator = false;
    basic_string<char, char_traits<char>, allocator<char>> _testPath = to_string(this->clientSocket) + "_test.csv";
    remove(_testPath.c_str());
}

void DataProvider::setTestFile(DataBase<double> *testFile) {
    this->testDB = testFile;
    this->testFileIndicator = true;
}

void DataProvider::resetTestFile() {
    this->testDB = nullptr;
    this->testFileIndicator = false;
    basic_string<char, char_traits<char>, allocator<char>> _trainPath = to_string(this->clientSocket) + "_train.csv";
    remove(_trainPath.c_str());
}


void DataProvider::setSin(struct sockaddr_in sin) {
    this->sin = sin;
}

void DataProvider::setClientSin(struct sockaddr_in clientSin) {
    this->clientSin = clientSin;
}

void DataProvider::setSockfd(int sockfd) {
    this->sockfd = sockfd;
}

void DataProvider::setClientSocket(int clientSocket) {
    this->clientSocket = clientSocket;
}

int DataProvider::getK() {
    return this->k;
}

Distance<double> *DataProvider::getMetric() {
    return this->metric;
}

DataBase<double> *DataProvider::getUnclassFile() {
    return this->unclassDB;
}

DataBase<double> *DataProvider::getTestFile() {
    return this->testDB;
}

struct sockaddr_in DataProvider::getSin() {
    return this->sin;
}

struct sockaddr_in DataProvider::getClientSin() {
    return this->clientSin;
}

int DataProvider::getSockfd() {
    return this->sockfd;
}

int DataProvider::getClientSocket() {
    return this->clientSocket;
}

bool DataProvider::isSetTestFile() {
    return this->testFileIndicator;
}

bool DataProvider::isSetUnclassFile() {
    return this->unclassIndicator;
}

void DataProvider::setClassifiedPath(basic_string<char, char_traits<char>, allocator<char>> filePath) {
    this->classifiedPath = filePath;
}

string DataProvider::getClassifiedPath() {
    return this->classifiedPath;
}

bool DataProvider::isClassifiedFile() {
    return this->isClassified;
}

bool DataProvider::isFinished() {
    return this->isExit;
}

void DataProvider::setFinished(bool finished) {
    this->isExit = finished;
}

void DataProvider::setClassifiedIndicator(bool indicator) {
    this->isClassified = indicator;
}

void DataProvider::resetClassifiedFile() {
    this->isClassified = false;
    basic_string<char, char_traits<char>, allocator<char>> _testPath = to_string(this->clientSocket) + "_classified.csv";
    remove(_testPath.c_str());
}


