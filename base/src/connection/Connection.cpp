#include "Connection.h"

namespace avansync {
    IO &Connection::getIO() const {
        return *_streamIO;
    }

    void Connection::close() {
        _stream->close();
    }
}