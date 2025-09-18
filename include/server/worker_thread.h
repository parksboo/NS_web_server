
#ifndef NSSERVER_WORKER_THREAD_H_
#define NSSERVER_WORKER_THREAD_H_

// related code
// /server/worker_thread.cc

// system header
#include <unistd.h>

// C++ standard library


namespace ns_server {

class Worker {
 public:
  explicit Worker(int fd) : client_fd_(fd) {}

  // 복사 금지, 이동 허용 (std::thread는 MoveConstructible 필요)
  Worker(const Worker&) = delete;
  Worker& operator=(const Worker&) = delete;
  Worker(Worker&& other) noexcept : client_fd_(other.client_fd_) { other.client_fd_ = -1; }
  Worker& operator=(Worker&& other) noexcept {
    if (this != &other) {
      close_now(); 
      client_fd_ = other.client_fd_;
      other.client_fd_ = -1;
    }
    return *this;
  }

  ~Worker() { close_now(); }

  void operator()() { Run(); }

 private:
  int client_fd_{-1};

  void close_now() {
    if (client_fd_ >= 0) { ::close(client_fd_); client_fd_ = -1; }
  }

  void Run();  // Run 안에서 close 하지 말고, 소멸자에 일원화 권장
};

}  // namespace ns_server

#endif  // NSSERVER_WORKER_THREAD_H_
