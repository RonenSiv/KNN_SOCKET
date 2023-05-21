
#ifndef ADVANCEDPROGRAMMINGR_O_DEFAULTIO_H
#define ADVANCEDPROGRAMMINGR_O_DEFAULTIO_H

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

/**
 * This class is responsible for the default IO.
 * It is an abstract class.
 * It is used to read and write from the client and the server.
 */
class DefaultIO {
protected:
    std::vector<std::string> _content{};    /// the content of the file
    std::string _buffer;                    /// the buffer of the input
    int _messageSize;                       /// the size of the message

public:
    /**
     * Constructor of the class.
     */
    DefaultIO();

    /**
     * Read function. Reads from the client or the server.
     * @return the string that was read.
     */
    virtual std::string read() = 0;

    /**
     * Write function. Writes to the client or the server.
     * @param string the text to be written.
     */
    virtual void write(std::string text) = 0;

    /**
     * Destructor of the class.
     */
    virtual ~DefaultIO() = default;

    /**
     * This function is responsible for setting the size of the message.
     * @param int the size of the message.
     */
    void setMessageSize(int size);

    /**
     * This function is responsible for getting the size of the message.
     * @return int the size of the message.
     */
    int getMessageSize();

    /**
     * This function is responsible for reading from a file.
     * @param file_path the path of the file to be read. and stores the content in the _content vector.
     * @return true if the file was read successfully, false otherwise.
     */
    bool readFromFile(std::basic_string<char> file_path);

    /**
     * This function is responsible for writing to a file.
     * @param file_path the path of the file to be written.
     * @param buffer the buffer to be written.
     * @return true if the file was written successfully, false otherwise.
     */
    bool writeToFile(const std::basic_string<char>& file_path, std::string &buffer);

    /**
     * This function is responsible for getting a line from the content vector.
     * @param int the line number to be returned.
     * @return the line that was requested.
     */
    std::string getLine(int line_number);

    /**
     * This function is responsible for setting the buffer.
     * @param buffer the buffer to be set.
     */
    void setBuffer(std::basic_string<char> buffer);

    /**
     * This function is responsible for emptying the buffer.
     */
    void emptyBuffer();

    /**
     * This function is responsible for getting the buffer.
     * @return string the buffer.
     */
    std::string getBuffer();

    /**
     * This function is responsible for adding a line to the content vector.
     * @param const std::basic_string<char>& the line to be added.
     */
    void addLineToContent(const std::basic_string<char> &line);

    /**
     * This function is responsible for copying the content to a vector.
     * @param std::vector<std::string>& the vector to be copied to.
     */
    void copyContentTo(std::vector<std::string> &content);

    /**
     * This function is responsible for getting the content.
     * @return std::vector<std::string> the content.
     */
    std::vector<std::string> getContent();
};


#endif //ADVANCEDPROGRAMMINGR_O_DEFAULTIO_H
