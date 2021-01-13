#include "Connection.h"

namespace avansync {
    IO& Connection::getIO() const {
        return *_streamIO;
    }

    void Connection::close() {
        _closed = true;
        _stream->close();
    }

    bool Connection::isOpen() const {
        return !_closed && (*_stream).operator bool();
    }

    std::wstring Connection::basedir() const {
        return L"./storage/";
    }
} // namespace avansync