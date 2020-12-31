#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <asio.hpp>
#include <connection/Connection.h>
#include <buffer/SystemIO.h>
#include <command/CommandRepository.h>
#include <util/ErrorUtil.h>
#include "command/ClientCommandRepository.h"

using namespace avansync;
using namespace asio::ip;

int main() {
    try {
        const char *server_address{"localhost"};
        const char *server_port{"12345"};
        const char *prompt{"avansync> "};

        CommandRepository commands = ClientCommandRepository{};
        SystemIO systemIO{};

        auto server = std::make_unique<tcp::iostream>(server_address, server_port);
        if (!server) throw std::runtime_error("could not connect to server");
        Connection connection{server};
        systemIO.writeLine(connection.getIO().readLine());

        while (connection.isOpen()) {
            std::cout << prompt;
            std::string command = systemIO.readLine().getContent();

            try {
                if (commands.hasCommand(command)) {
                    commands.execute(command, systemIO, connection);
                }
            } catch (const std::system_error &e) {
                systemIO.writeException(std::logic_error{ErrorUtil::getReason(e)});
            } catch (const std::exception &e) {
                systemIO.writeException(e);
            }
        }
    }
    catch (const std::exception &ex) {
        std::cerr << "client: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
