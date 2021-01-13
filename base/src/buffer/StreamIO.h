#pragma once

#include "IO.h"

#include <asio.hpp>
#include <memory>

using namespace asio::ip;

namespace avansync {
    class StreamIO : public IO {
    private:
        inline static const std::string LINE_BREAK = "\r\n";
        tcp::iostream& _stream;

    public:
        explicit StreamIO(tcp::iostream& stream) : _stream {stream} {};

        [[nodiscard]] Line readLine() override;

        void writeLine(const Line& data) override;

        void readFile(const std::wstring& path, int bytes) override;

        void writeFile(const std::wstring& path) override;
    };
} // namespace avansync