
// related header
#include "server/conn_manager.h"

// system header
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// C++ standard library

// project header
#include "util/timer.h"

namespace ns_server {

int ConnManager::createListenSocket(const int port) {
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0) return -1;
	sockaddr_in addr{};
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(port);
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