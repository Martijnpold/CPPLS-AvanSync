#pragma once

#include <buffer/ListIO.h>

using namespace avansync;

class TestIO : public ListIO {
public:
    std::string fileRead {};
    int readSize;

    std::string fileWritten {};

    void readFile(const std::string& path, int bytes) override {
        fileRead = path;
        readSize = bytes;
    }

    void writeFile(const std::string& path) override {
        fileWritten = path;
    }
};