#include <utility>
#include <vector>
#include <iostream>
#include "app/header/DefaultIO.h"

DefaultIO::DefaultIO() {
    _messageSize = 4096;
}

void DefaultIO::setMessageSize(int size) {
    if (_messageSize > 0) {
        _messageSize = size;
    }
}

int DefaultIO::getMessageSize() {
    return _messageSize;
}

bool DefaultIO::readFromFile(std::basic_string<char> file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty())
            _content.push_back(line);
    }
    file.close();
    return true;
}

bool DefaultIO::writeToFile(const std::basic_string<char> &file_path, std::string &buffer) {
    std::ofstream file(file_path);
    file << buffer;
    return true;
}

std::string DefaultIO::getBuffer() {
    std::stringstream ss;
    for (const auto &line: _content) {
        ss << line << std::endl;
    }
    _buffer = ss.str();
    return _buffer;
}

std::string DefaultIO::getLine(int line_number) {
    return _content[line_number];
}


void DefaultIO::addLineToContent(const std::basic_string<char> &line) {
    _content.push_back(line);
}

void DefaultIO::copyContentTo(std::vector<std::string> &content) {
    content.clear();
    for (const auto &line: _content) {
        content.push_back(line);
    }
}

std::vector<std::string> DefaultIO::getContent() {
    return _content;
}

void DefaultIO::setBuffer(std::basic_string<char> buffer) {
    _buffer = std::move(buffer);
}

void DefaultIO::emptyBuffer() {
    _content.clear();
    _buffer.clear();
}

