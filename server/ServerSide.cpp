/*
 * main function for the application "app"
 */

#include "ServerSide.h"


/**
 * this is the main function of the application
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "You have entered wrong number of command line arguments." << endl;
        cerr << "Please make sure that you are entering only one command line"
                " argument in a correct format." << endl;
        return 1;
    }

    TCP_Server server;
    if (!server.isValidPort(argv[1])) {
        cout << "Please enter a valid port number." << endl;
        return 1;
    }

    server.run();
    return 0;
}





