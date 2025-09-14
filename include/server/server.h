#ifndef NSSERVER_SERVER_H_
#define NSSERVER_SERVER_H_

#include <string>

namespace ns_server {

class Server {
 public:
  explicit Server(int port, std::string doc_root = "www");

  // Starts the server and runs until SIGINT is received.
  void Start();

  // Requests a clean shutdown.
  void Stop();

  // Non-copyable.
  Server(const Server&) = delete;
  Server& operator=(const Server&) = delete;

 private:
  const int port_;
  int server_fd_;
  std::string doc_root_;

  void HandleClient(int client_fd);
  int CreateListenSocket();
};

}  // namespace ns_server

#endif  // NSSERVER_SERVER_H_