// related header
#include "server/server.h"

// system header
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// C++ standard library
#include <string>
#include <iostream>

// project header
#include "http/status_codes.h"
#include "server/accept_loop.h"

// error handling edit
namespace ns_server {

Server::Server(int port, std::string doc_root)
		: port_(port), server_fd_(-1), doc_root_(std::move(doc_root)) {}

int Server::run() {
	// Create listening socket, accept loop, handle SIGINT for shutdown
	server_fd_ = createListenSocket();
	if (server_fd_ < 0) {
		return -1;
	}
	// Accept loop, call HandleClient for each connection on new thread
	std::cout << "Server running on port " << port_ << ", doc root: " << doc_root_ << "\n";
	AcceptLoop(server_fd_);
	return 0;	
}

int Server::createListenSocket() {

	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) return -1;
	sockaddr_in addr{};
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port_);
	if (bind(fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
		close(fd);
		return -1;
	}
	if (listen(fd, SOMAXCONN) < 0) {
		close(fd);
		return -1;
	}
	return fd;
}

}  // namespace ns_server

