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

    std::string Connection::basedir() const {
        return "./storage/";
    }
} // namespace avansync