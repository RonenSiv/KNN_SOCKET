#include "client/ClientSide.h"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3) {
        std::cerr << "Usage: client.out [ip] [port]" << std::endl;
        return 1;
    }

    if (ClientManager::getInstance(argv[1], argv[2]) == nullptr) {
        return 1;
    }

    TCPClient *client = ClientManager::getClient();

    if (!client->Connect()) {
        std::cerr << "Could not connect to server" << std::endl;
        return 1;
    }
    CLI cli = CLI(new StandardIO());

    while (true) {
        client->Send("menu");
        string menu = client->Receive();
        cli.write(menu);
        string menuOption = cli.read();
        try {
            if (!Util::is_number<int>(menuOption)) {
                throw std::invalid_argument("invalid");
            }
            cli.setCommand(ClientCommandFactory::createCommand(stoi(menuOption), cli.getDio(), client));
        } catch (std::exception &e) {
            client->Send("invalid");
            cli.write(client->Receive());
            continue;
        }
        client->Send(menuOption);
        cli.start();

        if (!client->CheckServerStatus() || !client->IsConnected()) {
            break;
        }

        string buffer = cli.getBuffer();
        if (buffer.empty() || !client->Send(buffer)) {
            // Sleep for 0.1 second to prevent the client from sending too many requests to the server
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        cli.emptyBuffer();

        // Sleep for 0.1 second to prevent the client from sending too many requests to the server
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}