#pragma once

#include <filesystem>
#include "../../../base/src/command/ICommand.h"

namespace avansync {
    class DirCommand : public ICommand {
    public:
        void execute(const IO &systemIO, const IConnection &connection) const override;

    private:
        [[nodiscard]] std::string toHash(const std::filesystem::directory_entry &file) const;

        template<typename TP>
        std::time_t to_time_t(TP tp) const {
            using namespace std::chrono;
            auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
            return system_clock::to_time_t(sctp);
        }
    };
}