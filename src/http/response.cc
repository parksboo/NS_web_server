
// related header
#include "http/response.h"

// system header
#include <sys/types.h>

// C++ standard library
#include <string>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <sys/stat.h>

#include <iostream>

// project header
#include "http/status_codes.h"
#include "http/mime_map.h"
#include "http/request.h"

namespace ns_http {

void Respond(int client_fd, Request& request) {
  if (request.path == "/") request.path = "/index.html";
  std::string filepath = "www" + request.path;
  // 404 Not Found
  if (access(filepath.c_str(), F_OK) != 0) {
    request.SetError(ns_http::StatusCode::NOT_FOUND);
  }
  else if (access(filepath.c_str(), R_OK) != 0) {
    if (errno == EACCES) {
      request.SetError(ns_http::StatusCode::FORBIDDEN);
    }
    else {
      request.SetError(ns_http::StatusCode::BAD_REQUEST);
    }
  }
  if (request.GetStatus() != StatusCode::OK) {
    return ErrorHandler(client_fd, request);
  }
  std::ifstream ifs(filepath, std::ios::binary);
  std::ostringstream oss;
  oss << ifs.rdbuf();
  request.body = oss.str();
  request.content_type = ns_http::MimeMap::GetMimeType(request.GetFileExtension());

  std::ostringstream resp;
  resp << request.version << " 200 OK" << "\r\n"
    << "Content-Type: " << request.content_type << "\r\n"
    << "Content-Length: " << request.body.size() << "\r\n"
    << "\r\n"
    << request.body;

  std::string response_str = resp.str();
  ::write(client_fd, response_str.c_str(), response_str.size());
}


void ErrorHandler(int client_fd, Request& request) {
  std::string status_text;
  switch (request.GetStatus()) {
    case StatusCode::BAD_REQUEST:
      status_text = "400 Bad Request";
      break;
    case StatusCode::FORBIDDEN:
      status_text = "403 Forbidden";
      break;
    case StatusCode::NOT_FOUND:
      status_text = "404 Not Found";
      break;
    case StatusCode::METHOD_NOT_ALLOWED:
      status_text = "405 Method Not Allowed";
      break;
    case StatusCode::HTTP_VERSION_NOT_SUPPORTED:
      status_text = "505 HTTP Version Not Supported";
      break;
    default:
      status_text = "500 Internal Server Error";
      break;
  }

  std::ostringstream resp;
  resp << request.version << " " << status_text << "\r\n"
       << "Content-Type: text/plain\r\n"
       << "Content-Length: " << std::to_string(status_text.size() + 1) << "\r\n"
       << "\r\n"
       << status_text << "\n";
  std::string response = resp.str();
    std::cout << resp.str() << std::endl; // Debug: Print the full response
    ::write(client_fd, response.c_str(), response.size());
}

}  // namespace ns_http
