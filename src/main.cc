// main.cc: Server entry point, argument parsing, server start/stop handling
#include <iostream>
#include <string>

#include "server/server.h"

int main(int argc, char* argv[]) {
    const int port = (argc > 1) ? std::stoi(argv[1]) : 9000;
    // const std::string docroot = (argc > 2) ? argv[2] : "www";
    const std::string docroot = "www";
    // Start server on specified port
    ns_server::Server server(port, docroot);
    server.start();

    return 0;
}
