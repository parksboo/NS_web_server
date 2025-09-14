// main.cc: Server entry point, argument parsing, server start/stop handling
#include <iostream>
#include <string>
#include "server/server.h"

int main(int argc, char* argv[]) {
    int port = (argc > 1) ? std::stoi(argv[1]) : 9000;
    std::string docroot = (argc > 2) ? argv[2] : "www";
    if (argc > 1) {
        port = std::stoi(argv[1]);
    }
    // Start server on specified port
    Server server(port, docroot);
    server.start();

    return 0;
}
