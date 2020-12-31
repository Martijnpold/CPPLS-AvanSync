#include "Line.h"

namespace avansync {
    Line::Line(std::string content) : _content{std::move(content)} {
    }

    Line::Line(const std::exception &content) : _content{"Error: " + std::string{content.what()}} {
    }

    bool Line::isError() {
        return _content.rfind("Error: ", 0) == 0;
    }

    const std::string &Line::getContent() const {
        return _content;
    }
}