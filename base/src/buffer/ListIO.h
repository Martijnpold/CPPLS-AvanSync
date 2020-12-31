#pragma once

#include "IO.h"

namespace avansync {
    class ListIO : public IO {
    private:
        std::vector<Line> _writeLines;
        std::vector<Line> _readLines;

    public:
        [[nodiscard]] Line readLine() override;

        void writeLine(const Line& data) override;

        void readFile(const std::string& path, int bytes) override;

        void writeFile(const std::string& path) override;

        [[nodiscard]] std::vector<Line> getWrittenLines() const;

        [[nodiscard]] std::vector<Line> getReadLines() const;

        void addReadLine(const Line& line);
    };
} // namespace avansync