#pragma once

#include <ostream>
#include <string>

namespace avansync {
    class Line {
    private:
        std::string _content;

    public:
        explicit Line(std::string content);

        explicit Line(const std::exception& content);

        bool isError();

        [[nodiscard]] const std::string& getContent() const;
    };

    inline std::ostream& operator<<(std::ostream& os, const Line& line) {
        os << line.getContent();
        return os;
    }
} // namespace avansync