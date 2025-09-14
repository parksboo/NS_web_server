// related header
#include "server/server.h"

// system header
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>

// C++ standard library
#include <string>
#include <stdexcept>

// project header

// error handling edit
namespace ns_server {

Server::Server(int port, const std::string doc_root)
		: port_(port), server_fd_(-1), doc_root_(std::move(doc_root)) {}

void Server::start() {
	// TODO: Create listening socket, accept loop, handle SIGINT for shutdown
	server_fd_ = createListenSocket();
	if (server_fd_ < 0) {
		throw std::runtime_error("Failed to create server socket: " + std::string(strerror(errno)));
	}
	std::cout << "Server started on port " << port_ << ", doc_root: " << doc_root_ << std::endl;
	// TODO: Accept loop, call HandleClient for each connection
}

void Server::stop() {
	// TODO: Implement graceful shutdown
	if (server_fd_ >= 0) {
		close(server_fd_);
		server_fd_ = -1;
		std::cout << "Server stopped." << std::endl;
	}
}

void Server::handleClient(int client_fd) {
	// TODO: Read request, parse, generate response, send back
	// Placeholder for client handling logic
	close(client_fd);
}

int Server::createListenSocket() {
	// TODO: Create, bind, listen on socket
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
	if (listen(fd, 16) < 0) {
		close(fd);
		return -1;
	}
	return fd;
}

}  // namespace ns_server

