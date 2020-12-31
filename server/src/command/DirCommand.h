#pragma once

#include <command/ICommand.h>
#include <filesystem>

namespace avansync {
    class DirCommand : public ICommand {
    public:
        void execute(IO& systemIO, IConnection& connection) const override;

    private:
        [[nodiscard]] std::string toHash(const std::filesystem::directory_entry& file) const;

        template<typename TP> std::time_t to_time_t(TP tp) const {
            using namespace std::chrono;
            auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now() + system_clock::now());
            return system_clock::to_time_t(sctp);
        }
    };
} // namespace avansync