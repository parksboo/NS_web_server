#ifndef NSSERVER_SERVER_H_
#define NSSERVER_SERVER_H_

// related code
// /server/worker_thread.cc

// system header
#include <unistd.h>

// C++ standard library
#include <string>

namespace ns_server {

class Server {
 public:
  explicit Server(int port, std::string doc_root = "www");

  // Starts the server and runs until SIGINT is received.
  int run();

  // Non-copyable.
  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

 private:
  int port_;
  int server_fd_;
  const std::string doc_root_;

  int createListenSocket();
};

}  // namespace ns_server

#endif  // NSSERVER_SERVER_H_