// main.cc: Server entry point, argument parsing, server start/stop handling
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    // TODO: port argument parsing and server execution
    int port = 8888; // Default port
    if (argc > 1) {
        port = std::stoi(argv[1]);
    }
    // Start server on specified port

    return 0;
}
