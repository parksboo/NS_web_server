
// related header
#include "server/worker_thread.h"

// system header
#include <sys/socket.h>
#include <poll.h>

// C++ standard library
#include <thread>


// project header
#include "http/request.h"
#include "http/response.h"
#include "util/strutil.h"

namespace ns_server {

void Worker::Run() {
  ::timeval tv{10, 0};
  ::setsockopt(client_fd_, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
  ::setsockopt(client_fd_, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));

  constexpr int keepAliveMs = 10 * 1000;

  for (;;) {
    ns_http::Request request = ns_http::Get(client_fd_);
    ns_http::Respond(client_fd_, request);
    if (!(ns_util::ToLower(request.headers["Connection"]) == "keep-alive")) {
      break;
    }
    ::pollfd pfd{ client_fd_, POLLIN, 0 };
    int pr = ::poll(&pfd, 1, keepAliveMs);
    if (pr <= 0) {
      break;
    }
  }
}
    
}  // namespace ns_server

