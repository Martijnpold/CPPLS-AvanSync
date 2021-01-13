#pragma once

#include <string>
#include <sstream>

namespace avansync {
    class Line {
    private:
        std::wstring _content;

    public:
        explicit Line(std::wstring content);

        explicit Line(const std::string& content);

        explicit Line(const std::exception& content);

        bool isError();

        [[nodiscard]] const std::wstring& getWContent() const;

        [[nodiscard]] const std::string getContent() const;
    };

    inline std::ostream& operator<<(std::ostream& os, const Line& line) {
        os << line.getContent();
        return os;
    }

    inline std::wostream& operator<<(std::wostream& os, const Line& line) {
        os << line.getWContent();
        return os;
    }
} // namespace avansync