#include "Connection.h"

namespace avansync {
    IO& Connection::getIO() const {
        return *_streamIO;
    }

    void Connection::close() const {
        _stream->close();
    }

    bool Connection::isOpen() const {
        return (*_stream).operator bool();
    }
} // namespace avansync