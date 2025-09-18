
// related header
#include "server/accept_loop.h"

// system header
#include <sys/socket.h>
#include <netinet/in.h>

// C++ standard library
#include <thread>

// project header
#include "server/worker_thread.h"

namespace ns_server {
void AcceptLoop(int server_fd) {
    while (true) {
		sockaddr_in client_addr{};
		socklen_t client_len = sizeof(client_addr);
		int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);
		if (client_fd < 0) continue;  // Accept failed, try again
        std::thread(Worker{client_fd}).detach();
	}
}

}  // namespace ns_server
