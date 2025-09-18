
// related header
#include "server/worker_thread.h"

// system header
#include <sys/socket.h>
#include <sys/stat.h>

// C++ standard library
#include <thread>
#include <iostream>
#include <sstream>
#include <fstream>

// project header
#include "http/request.h"
#include "http/status_codes.h"
#include "http/mime_map.h"
#include "http/response.h"

namespace ns_server {

void Worker::Run() {
  
  ns_http::Request request = ns_http::Get(client_fd_);
  ns_http::Respond(client_fd_, request);
}

}  // namespace ns_server

