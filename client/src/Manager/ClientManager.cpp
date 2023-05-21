
#include "client/header/Manager/ClientManager.h"

TCPClient *ClientManager::getClient() {
    return _client;
}

ClientManager *ClientManager::getInstance(const std::string &ip, const std::string &port) {
    if (_instance == nullptr) {
        int portNum;
        try {
            portNum = stoi(port);
            _client = new TCPClient(ip, portNum);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return nullptr;
        }

        _instance = new ClientManager();

    }
    return _instance;
}

ClientManager *ClientManager::_instance = nullptr;
TCPClient *ClientManager::_client = nullptr;