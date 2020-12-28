#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <asio.hpp>
#include "../../base/src/connection/Connection.h"

using namespace asio::ip;

int main() {
    try {
        const char *server_address{"localhost"};
        const char *server_port{"12345"};
        const char *prompt{"avansync> "};
        const char *lf{"\n"};
        const char *crlf{"\r\n"};

        auto server = std::make_unique<tcp::iostream>(server_address, server_port);
        if (!server) throw std::runtime_error("could not connect to server");
        auto connection = std::make_unique<avansync::Connection>(server);

        while (connection) {
            std::string resp = connection->getIO().readLine();
            resp.erase(resp.end() - 1); // remove '\r'
            std::cout << resp << lf;
            if (resp == "Bye.") break;

            std::cout << prompt;
            std::string req;
            if (getline(std::cin, req)) {
                connection->getIO().writeLine(req + crlf);
                connection->getIO().readFile("./test.txt", 5);
            }
        }

    }
    catch (const std::exception &ex) {
        std::cerr << "client: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
