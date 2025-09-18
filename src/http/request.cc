// related header
#include "http/request.h"

// system header
#include <sys/types.h>
#include <unistd.h>

// C++ standard library
#include <string>
#include <map>
#include <sstream>

// project header
#include "util/strutil.h"

namespace ns_http {

Request::Request() : method(""), path(""), version(""), headers() {}

Request Get(int client_fd) {
  char buf[4096];

  ssize_t n = ::read(client_fd, buf, sizeof(buf) - 1);
  if (n <= 0) return Request();
  buf[n] = '\0';
  return Parse(buf);
}

Request Parse(const std::string& raw_request) {
    Request request;
    std::istringstream iss(raw_request);
    std::string line;

    // Parse request line
    std::getline(iss, line);
    std::istringstream line_iss(line);
    line_iss >> request.method >> request.path >> request.version;

    // Parse headers
    while (std::getline(iss, line) && line != "\r") {
        std::string key, value;
        std::size_t colon_pos = line.find(':');
        if (colon_pos != std::string::npos) {
            key = line.substr(0, colon_pos);
            value = line.substr(colon_pos + 1);
            request.headers[ns_util::Trim(key)] = ns_util::Trim(value);
        }
    }

    return request;
}

std::string Request::GetFileExtension() {
    size_t dot_pos = path.rfind('.');
    if (dot_pos != std::string::npos) {
        return path.substr(dot_pos);
    }
    return "";
}

}  // namespace ns_http
