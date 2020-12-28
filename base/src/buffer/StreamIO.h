#pragma once

#include "IO.h"
#include <memory>
#include <asio.hpp>

using namespace asio::ip;

namespace avansync {
    class StreamIO : public IO {
    private:
        tcp::iostream &_stream;
    public:
        explicit StreamIO(tcp::iostream &stream) : _stream{stream} {};

        std::string readLine() override;

        void writeLine(std::string data) override;

        void readFile(std::string path, int bytes) override;

        void writeFile(std::string path) override;
    };
}