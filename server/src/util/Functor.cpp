//
// Created by ofirhelerman on 1/24/23.
//

#include "server/header/util/Functor.h"
#include "server/header/DIO/SocketIO.h"
#include "app/header/CLI.h"
#include "server/header/factory/ServerCommandFactory.h"
#include "server/header/util/Util.h"


Functor::Functor(sockaddr_in sin, sockaddr_in clientSin, int serverSocket, int clientSocket) {
    this->serverSin = sin;
    this->clientSin = clientSin;
    this->serverSocket = serverSocket;
    this->clientSocket = clientSocket;
}

static std::string createMenu(ServerCommandFactory &commandFactory) {
    vector<Command *> commands;
    commands.push_back(commandFactory.createCommand(1));
    commands.push_back(commandFactory.createCommand(2));
    commands.push_back(commandFactory.createCommand(3));
    commands.push_back(commandFactory.createCommand(4));
    commands.push_back(commandFactory.createCommand(5));
    commands.push_back(commandFactory.createCommand(8));

    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    int index = 1;
    for (Command *temp: commands) {

        menu += std::to_string(index == 6 ? 8 : index) + ". " + temp->getCommandDescription() +
                (index == 6 ? "" : "\n");
        index++;
    }
    return menu;
}


void Functor::setIsFinished(bool isFinished) {
    this->isFinished = isFinished;
}

void Functor::operator()() {
    auto *dataProvider = new DataProvider();
    dataProvider->setSin(this->serverSin);
    dataProvider->setClientSin(this->clientSin);
    dataProvider->setClientSocket(this->clientSocket);
    dataProvider->setSockfd(this->serverSocket);
    std::string path = std::to_string(this->clientSocket) + "_classified.csv";
    dataProvider->setClassifiedPath(path);

    DefaultIO *dio = new SocketIO(dataProvider);
    CLI cli;
    cli.setDio(dio);

    ServerCommandFactory commandFactory(dio, dataProvider, this);
    string menu = createMenu(commandFactory);
    while (!this->isFinished) {
        string message = dio->read();

        if (message == "Client disconnected") {
            this->isFinished = true;
            break;
        }

        while (message != "menu") {
            message = dio->read();
        }

        dio->write(menu);

        message = dio->read();
        if (message == "invalid") {
            dio->write("Error: invalid input");
            continue;
        }

        int option;
        try {
            if (!Util::is_number<int>(message)) throw "not an integer";
            option = std::stoi(message);
        } catch (...) {
            dio->write("Error: problem with converting the option number");
            continue;
        }
        try {
            Command *command = commandFactory.createCommand(option);
            cli.setCommand(command);
        } catch (...) {
            dio->write("Error: problem with creating the command");
            continue;
        }
        cli.start();
    }
}
