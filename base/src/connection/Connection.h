#pragma once

#include "../buffer/StreamIO.h"
#include "IConnection.h"

#include <asio.hpp>

using namespace asio::ip;

namespace avansync {
    class Connection : public IConnection {
    private:
        std::unique_ptr<tcp::iostream> _stream;
        std::unique_ptr<StreamIO> _streamIO;
        bool _closed {false};

    public:
        explicit Connection(std::unique_ptr<tcp::iostream>& stream)
            : _stream {std::move(stream)}, _streamIO {std::make_unique<StreamIO>(*_stream)} {
        }

        [[nodiscard]] IO& getIO() const override;

        void close() override;

        [[nodiscard]] bool isOpen() const override;
        std::wstring basedir() const override;
    };
} // namespace avansync