#pragma once

#include "IO.h"
#include <memory>
#include <asio.hpp>

using namespace asio::ip;

namespace avansync {
    class StreamIO : public IO {
    private:
        inline static const std::string LINE_BREAK = "\r\n";
        tcp::iostream &_stream;

    public:
        explicit StreamIO(tcp::iostream &stream) : _stream{stream} {};

        [[nodiscard]] std::string readLine() const override;

        void writeLine(const std::string &data) const override;

        void readFile(const std::string &path, int bytes) const override;

        void writeFile(const std::string &path) const override;
    };
}