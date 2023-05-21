//
// Created by ofirhelerman on 1/21/23.
//

#ifndef ADVANCEDPROGRAMMINGR_O_SOCKETIO_H
#define ADVANCEDPROGRAMMINGR_O_SOCKETIO_H


#include "app/header/DefaultIO.h"
#include "server/header/util/DataProvider.h"

/**
 * SocketIO class
 */
class SocketIO : public DefaultIO {

private:
    DataProvider *_dataProvider;    // the data provider
public:
    /**
     * Constructor
     * @param DataProvider* - the data provider
     */
    explicit SocketIO(DataProvider *dataProvider);

    /**
     * read from the client and server socket
     * @return
     */
    string read() override;

    /**
     * write to the client and server socket
     * @param string - the text to write
     */
    void write(string text) override;

    /**
     * override the destructor of DefaultIO
     */
    ~SocketIO() override;
};


#endif //ADVANCEDPROGRAMMINGR_O_SOCKETIO_H
