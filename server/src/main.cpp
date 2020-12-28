#include <iostream>
#include <cstdlib>
#include <string>
#include <asio.hpp>
#include "../../base/src/command/CommandRepository.h"
#include "command/ServerCommandRepository.h"
#include "../../base/src/connection/Connection.h"
#include "../../base/src/buffer/SystemIO.h"

using namespace asio::ip;
using namespace avansync;

int main() {
    try {
        const int server_port{12345};

        CommandRepository commands = ServerCommandRepository{};
        SystemIO systemIO{};

        asio::io_context io_context;
        asio::ip::tcp::acceptor server{io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port)};

        for (;;) {
            std::cerr << "waiting for client to connect\n";
            auto client = std::make_unique<tcp::iostream>();
            server.accept(client->socket());
            std::cerr << "client connected from " << client->socket().local_endpoint() << std::endl;

            Connection connection{client};
            connection.getIO().writeLine("Welcome to AvanSync server 1.0");

            for (;;) {
                std::string request = connection.getIO().readLine();
                systemIO.writeLine("Received request " + request);

                if(commands.hasCommand(request)) {
                    commands.execute(request, systemIO, connection);
                }
            }
        }
    }
    catch (const std::exception &ex) {
        std::cerr << "server: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
