#pragma once

#include <asio.hpp>
#include "IConnection.h"
#include "../buffer/StreamIO.h"

using namespace asio::ip;

namespace avansync {
    class Connection : public IConnection {
    private:
        std::unique_ptr<tcp::iostream> _stream;
        std::unique_ptr<StreamIO> _streamIO;

    public:
        explicit Connection(std::unique_ptr<tcp::iostream>& stream) : _stream{std::move(stream)},
                                                                     _streamIO{std::make_unique<StreamIO>(*_stream)} {}

        [[nodiscard]] IO &getIO() const override;

        void close() const override;

        [[nodiscard]] bool isOpen() const override;
    };
}