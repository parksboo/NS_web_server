
#ifndef NSSERVER_WORKER_THREAD_H_
#define NSSERVER_WORKER_THREAD_H_

// related code
// /server/worker_thread.cc

// system header
#include <unistd.h>

// C++ standard library

// project header


namespace ns_server {

class Worker {

 public:
    explicit Worker(int fd) : client_fd_(fd) {}
    
    // Non-copyable
    Worker(const Worker&) = delete;
    Worker& operator=(const Worker&) = delete;
    Worker(Worker&&) = default;
    Worker& operator=(Worker&&) = default;
    ~Worker() { if (client_fd_ >= 0) ::close(client_fd_); }

    void operator()() { Run(); }

    private:
    int client_fd_;  // 인스턴스마다 독립. 이름이 같아도 전혀 충돌 없음.

    void Run() {
        // 여기서 client_fd_로 recv/send 루프
    }
};

}  // namespace ns_server

#endif  // NSSERVER_WORKER_THREAD_H_
