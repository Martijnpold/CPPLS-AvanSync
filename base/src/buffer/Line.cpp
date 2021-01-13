#include "Line.h"

#include <utility>

namespace avansync {
    Line::Line(std::wstring content) : _content {std::move(content)} {
    }

    Line::Line(const std::string& content) : Line(std::wstring {content.begin(), content.end()}) {
    }

    Line::Line(const std::exception& content) : Line("Error: " + std::string {content.what()}) {
    }

    bool Line::isError() {
        return _content.rfind(L"Error: ", 0) == 0;
    }

    const std::wstring& Line::getWContent() const {
        return _content;
    }

    const std::string Line::getContent() const {
        return {_content.begin(), _content.end()};
    }
} // namespace avansync