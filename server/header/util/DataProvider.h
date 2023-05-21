

#ifndef ADVANCEDPROGRAMMINGR_O_DATAPROVIDER_H
#define ADVANCEDPROGRAMMINGR_O_DATAPROVIDER_H


#include <netinet/in.h>
#include <string>
#include "server/header/distance/Distance.h"
#include "server/header/database/DataBase.h"

/**
 * This class is a mechanism to share data between different commands.
 */

class DataProvider {
public:

    /**
     * Constructor
     */
    DataProvider();

    /**
     * Destructor
     */
    ~DataProvider() = default;

    /**
     * Set the k value
     * @param k the k value
     */
    void setK(int k);

    /**
     * Set the metric
     * @param metric the metric
     */
    void setMetric(Distance<double> *metric);

    /**
     * Set the unclassified file
     * @param unclassFile the unclassified file
     */
    void setUnclassFile(DataBase<double> *unclassFile);

    /**
     * Set the test file
     * @param testFile the test file
     */
    void setTestFile(DataBase<double> *testFile);

    /**
     * Set the socket address
     * @param sin the socket address
     */
    void setSin(struct sockaddr_in sin);

    /**
     * Set the client socket address
     * @param clientSin the client socket address
     */
    void setClientSin(struct sockaddr_in clientSin);

    /**
     * Set the socket file descriptor
     * @param sockfd the socket file descriptor
     */
    void setSockfd(int sockfd);

    /**
     * Set the client socket file descriptor
     * @param clientSocket the client socket file descriptor
     */
    void setClientSocket(int clientSocket);

    /**
     * Set the classified path
     * @param filePath the classified path
     */
    void setClassifiedPath(basic_string<char, char_traits<char>, allocator<char>> filePath);

    /**
     * Set the exit flag
     * @param exit the exit flag
     */
    void setFinished(bool finished);

    /**
     * Set the isClassified flag
     * @param indicator the isClassified flag
     */
    void setClassifiedIndicator(bool indicator);

    /**
     * Boolean function to check if the train file is set
     */
    bool isSetTestFile();

    /**
     * Boolean function to check if the test file is set
     */
    bool isSetUnclassFile();

    /**
     * Boolean function to check if the file is classified
     */
    bool isClassifiedFile();

    /**
     * Boolean function to check if the thread should exit
     */
    bool isFinished();

    /**
     * Get the k value
     * @return the k value
     */
    int getK();

    /**
     * Get the metric
     * @return the metric
     */
    Distance<double> *getMetric();

    /**
     * Get the unclassified file
     * @return the unclassified file
     */
    DataBase<double> *getUnclassFile();

    /**
     * Get the test file
     * @return the test file
     */
    DataBase<double> *getTestFile();

    /**
     * Get the socket address
     * @return the socket address
     */
    struct sockaddr_in getSin();

    /**
     * Get the client socket address
     * @return the client socket address
     */
    struct sockaddr_in getClientSin();

    /**
     * Get the socket file descriptor
     * @return the socket file descriptor
     */
    int getSockfd();

    /**
     * Get the client socket file descriptor
     * @return the client socket file descriptor
     */
    int getClientSocket();

    /**
     * Get the classified path
     * @return the classified path
     */
    string getClassifiedPath();

    /**
     * Reset any data thats regarding the test file
     */
    void resetTestFile();

    /**
     * Reset any data thats regarding the unclassified file
     */
    void resetUnclassFile();

    /**
     * Reset any data thats regarding the classified file
     */
    void resetClassifiedFile();



private:
    struct sockaddr_in sin;                 /// socket address
    struct sockaddr_in clientSin;           /// client socket address
    int sockfd;                             /// socket file descriptor
    int clientSocket;                       /// client socket file descriptor
    DataBase<double> *unclassDB;            /// unclassified file
    DataBase<double> *testDB;               /// test file
    int k;                                  /// k value
    Distance<double> *metric;               /// metric
    bool unclassIndicator;                  /// indicator if the unclassified file is set
    bool testFileIndicator;                 /// indicator if the test file is set
    bool isClassified;                      /// indicator if the file is classified
    bool isExit;                            /// indicator if the thread should exit
    string classifiedPath;                  /// classified path
};


#endif //ADVANCEDPROGRAMMINGR_O_DATAPROVIDER_H
