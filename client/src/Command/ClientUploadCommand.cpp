#include "client/header/Command/ClientUploadCommand.h"

using namespace std;

void ClientUploadCommand::execute() {
    // local train file
    _dio->write(_client->Receive());
    std::string file_name = _dio->read();
    if (!_dio->readFromFile(file_name) || _dio->getContent().empty()) {
        _client->Send("failed");
        _dio->write(_client->Receive());
        _dio->emptyBuffer();
        return;
    }
    // Get the size of the file
    std::ifstream train_file(file_name);
    train_file.seekg(0, std::ios::end);
    int file_size = train_file.tellg();
    train_file.seekg(0, std::ios::beg);
    // Send the file size and the file
    _client->Send(std::to_string(file_size));
    for (std::string line: _dio->getContent()) {
        std::stringstream ss;
        ss << line << std::endl;
        _client->Send(ss.str());
        _client->Receive();
    }
    _client->Send("EOF");
    std::string msg = _client->Receive();
    _dio->emptyBuffer();

    while (msg != "Upload complete.\nPlease upload your local test CSV file.") {
        msg = _client->Receive();
        if (msg == "invalid input") {
            return;
        }
    }
    _dio->write(msg);

    // local test file
    file_name = _dio->read();
    if (!_dio->readFromFile(file_name) || _dio->getContent().empty()) {
        _client->Send("failed");
        _dio->write(_client->Receive());
        _dio->emptyBuffer();
        return;
    }
    // Get the size of the file
    std::ifstream test_file(file_name);
    test_file.seekg(0, std::ios::end);
    file_size = test_file.tellg();
    test_file.seekg(0, std::ios::beg);
    _client->Send("sentSize");
    _client->Send(std::to_string(file_size));
    msg = _client->Receive();
    while (msg != "sendFile") {
        msg = _client->Receive();
        if (msg == "invalid input") {
            return;
        }
    }
    _client->Send("sentFile");
    for (std::string line: _dio->getContent()) {
        std::stringstream ss;
        ss << line << std::endl;
        _client->Send(ss.str());
        _client->Receive();
    }
    _client->Send("EOF");
    _dio->write(_client->Receive());
    _dio->emptyBuffer();
}

ClientUploadCommand::ClientUploadCommand() {
    ClientUploadCommand::setCommandDescription("upload an unclassified csv data file");
}

ClientUploadCommand::ClientUploadCommand(DefaultIO *dio, TCPClient *client) {
    ClientUploadCommand::setCommandDescription("upload an unclassified csv data file");
    _dio = dio;
    _client = client;
}

void ClientUploadCommand::setClient(TCPClient *pClient) {
    _client = pClient;
}

