
// related header
#include "server/worker_thread.h"

// system header
#include <sys/socket.h>

// C++ standard library
#include <thread>

// project header
#include "util/log.h"

namespace ns_server {

void Worker::Run() {
    // 예시: 간단히 클라이언트에게 환영 메시지 전송 후 종료
    const char* welcome_msg = "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!";
    send(client_fd_, welcome_msg, strlen(welcome_msg), 0);
}

}  // namespace ns_server

