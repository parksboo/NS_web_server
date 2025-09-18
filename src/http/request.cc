// related header
#include "http/request.h"

// system header
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

// C++ standard library
#include <string>
#include <set>
#include <map>
#include <sstream>
// #include <iostream>

// project header
#include "util/strutil.h"
#include "http/status_codes.h"

namespace ns_http {

static const std::set<std::string> supported_methods = {"GET"};
static const std::set<std::string> supported_versions = {"HTTP/1.1", "HTTP/1.0"};

Request::Request() : method(""), path(""), version("HTTP/1.1"), headers(), error_message_(StatusCode::OK) {}

Request Get(int client_fd) {
  std::string request_str;
  char buf[4096];

  while (request_str.find("\r\n\r\n") == std::string::npos) {
    ssize_t bytes_read = recv(client_fd, buf, sizeof(buf), 0);
    if (bytes_read <= 0) return Request().SetError(StatusCode::BAD_REQUEST);
    request_str.append(buf, bytes_read);
    //  // Debug: Print received chunk
    //   std::cout << "--- Received chunk (" << bytes_read << " bytes) ---" << std::endl;
    //   std::cout.write(buf, bytes_read);
    //   std::cout << "--------------------------" << std::endl;
  }
  return Parse(request_str);
}

Request Parse(const std::string& raw_request) {
  Request request;
  std::istringstream iss(raw_request);
  std::string line;

  // Parse request line
  std::getline(iss, line);
  std::istringstream line_iss(line);
  line_iss >> request.method >> request.path >> request.version;

  // 405 Method Not Allowed
  if (supported_methods.find(request.method) == supported_methods.end()) {
    return request.SetError(StatusCode::METHOD_NOT_ALLOWED);
  }
  // 505 HTTP Version Not Supported
  if (supported_versions.find(request.version) == supported_versions.end()) {
    return request.SetError(StatusCode::HTTP_VERSION_NOT_SUPPORTED);
  }
  // 400 Bad Request
  if (line_iss.fail() || request.method.empty() || request.path.empty() || request.version.empty()) {
    return request.SetError(StatusCode::BAD_REQUEST);
  }

  // Parse headers
  while (std::getline(iss, line) && !ns_util::Trim(line).empty()) {
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
    return path.substr(dot_pos + 1);
  }
  return "";
}

Request& Request::SetError(StatusCode code) {
  error_message_ = code;
  return *this;
}

}  // namespace ns_http
