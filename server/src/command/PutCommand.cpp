#include "PutCommand.h"

#include <util/ErrorUtil.h>

namespace avansync {
    void PutCommand::execute(IO& systemIO, IConnection& connection) const {
        try {
            std::string path {"./storage/" + connection.getIO().readLine().getContent()};
            int fileSize {std::stoi(connection.getIO().readLine().getContent())};

            systemIO.writeString("Saving " + std::to_string(fileSize) + " bytes " + path);
            connection.getIO().readFile(path, fileSize);
            connection.getIO().writeString("OK");
        } catch (const std::system_error& e) {
            systemIO.writeException(std::logic_error {ErrorUtil::getReason(e)});
            connection.getIO().writeException(std::logic_error {ErrorUtil::getReason(e)});
        }
    }
} // namespace avansync