#include "command/ServerCommandRepository.h"

#include <asio.hpp>
#include <buffer/SystemIO.h>
#include <command/CommandRepository.h>
#include <connection/Connection.h>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

using namespace asio::ip;
using namespace avansync;
using namespace avansync::server;

int main() {
    const int server_port {25568};

    CommandRepository commands = ServerCommandRepository {};
    SystemIO systemIO {};

    asio::io_context io_context;
    asio::ip::tcp::acceptor server {io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), server_port)};

    for (;;) {
        try {
            std::cerr << "waiting for client to connect\n";
            auto client = std::make_unique<tcp::iostream>();
            server.accept(client->socket());
            std::cerr << "client connected from " << client->socket().local_endpoint() << std::endl;

            Connection connection {client};
            fs::create_directories(connection.basedir());
            connection.getIO().writeString("Welcome to AvanSync server 1.0");

            while (connection.isOpen()) {
                Line request = connection.getIO().readLine();
                systemIO.writeString("Received " + request.getContent());

                try {
                    if (commands.hasCommand(request.getContent())) {
                        commands.execute(request.getContent(), systemIO, connection);
                    }
                } catch (const std::exception& e) {
                    systemIO.writeString("Uncaught exception:");
                    systemIO.writeException(e);
                }
            }
        } catch (const std::exception& ex) {
            std::cerr << "server: " << ex.what() << '\n';
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
