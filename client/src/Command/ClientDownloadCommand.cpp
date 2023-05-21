#include <thread>
#include <filesystem>
#include "client/header/Command/ClientDownloadCommand.h"

void ClientDownloadCommand::execute() {
    std::thread downloadThread([&]() {
        std::string line = _client->Receive();
        if (line.find("please") != std::string::npos || line.find("Error") != std::string::npos) {
            _dio->write(line);
            _dio->emptyBuffer();
            return;
        }
        std::string file_path = _dio->read();

        std::ofstream file(file_path);
        if (!file.is_open()) {
            _client->Send("failed");
            _dio->write("Error occurred: could not open the file, please try again.");
            _dio->emptyBuffer();
            return;
        }

        _client->Send("ok");
        while (line != "eof") {
            _client->Send("ok");
            if (line == "ok") {
                line = _client->Receive();
                continue;
            }
            file << line << std::endl;
            if (line == "eof")
                break;

            line = _client->Receive();
        }
        file.close();
        _dio->emptyBuffer();
    });
    downloadThread.join();
}

ClientDownloadCommand::ClientDownloadCommand() {
    ClientDownloadCommand::setCommandDescription("download results");
}

ClientDownloadCommand::ClientDownloadCommand(DefaultIO *dio, TCPClient *client) {
    ClientDownloadCommand::setCommandDescription("download results");
    ClientDownloadCommand::setDio(dio);
    ClientDownloadCommand::setClient(client);
}

void ClientDownloadCommand::setClient(TCPClient *pClient) {
    _client = pClient;
}