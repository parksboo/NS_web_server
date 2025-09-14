#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    explicit Server(int port, std::string doc_root = "www");
    void start(); // terminate on SIGINT
    void stop();
private:
    int port_;
    int server_fd_;
    std::string doc_root_;

    void handleClient(int client_fd);
    int createListenSocket();
};

#endif