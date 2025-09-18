
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
#include "http/mime_map.h"

namespace ns_server {

void Worker::Run() {
  
  ns_http::Request request = ns_http::Get(client_fd_);

  // 2. 첫 줄 파싱 (예: "GET /index.html HTTP/1.1")
  if (request.method != "GET") {
    const char* notimpl =
        "HTTP/1.0 501 Not Implemented\r\nContent-Length: 0\r\n\r\n";
    ::write(client_fd_, notimpl, strlen(notimpl));
    return;
  }

  // 3. 경로 보안 처리 ("/" → "/index.html")
  if (request.path == "/") request.path = "/index.html";
  std::string filepath = "www" + request.path;

  // 4. 파일 존재 확인
  struct stat st;
  if (stat(filepath.c_str(), &st) != 0) {
    std::string notfound =
        request.version + " 404 Not Found\r\nContent-Type: text/plain\r\n"
        "Content-Length: 13\r\n\r\n404 Not Found\n";
    ::write(client_fd_, notfound.c_str(), notfound.size());
    return;
  }

  // 5. 파일 읽기
  std::ifstream ifs(filepath, std::ios::binary);
  std::ostringstream oss;
  oss << ifs.rdbuf();
  std::string body = oss.str();

  // 6. 간단한 MIME type 결정 (확장자 기준)
  std::string content_type = ns_http::MimeMap::GetMimeType(request.GetFileExtension());



  // 7. 응답 작성
  std::ostringstream resp;
  resp << request.version << " 200 OK\r\n"
       << "Content-Type: " << content_type << "\r\n"
       << "Content-Length: " << body.size() << "\r\n"
       << "\r\n"
       << body;

  std::string response = resp.str();

  // 8. 전송
  ::write(client_fd_, response.c_str(), response.size());
}

}  // namespace ns_server

