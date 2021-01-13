#pragma once

#include "IO.h"

namespace avansync {
    class ListIO : public IO {
    private:
        std::vector<Line> _writeLines;

    public:
        [[nodiscard]] Line readLine() override;

        [[nodiscard]] Line getReadLine(int index) const;

        void writeLine(const Line& data) override;

        void readFile(const std::string& path, int bytes) override;

        void writeFile(const std::string& path) override;

        [[nodiscard]] std::vector<Line> getReadLines() const;

        void addReadLine(const Line& line);

        [[nodiscard]] int getWrittenLineCount() const;
    };
} // namespace avansync