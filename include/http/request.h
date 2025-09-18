
#ifndef NSHTTP_REQUEST_H_
#define NSHTTP_REQUEST_H_

#include <string>
#include <map>

#include "http/status_codes.h"

namespace ns_http {

class Request {
 public:
    std::string method;
    std::string path;
    std::string version;
	std::string body;
	std::string content_type;
    std::map<std::string, std::string> headers;
	
	Request();
	
	std::string GetFileExtension();
	Request& SetError(StatusCode code);
	StatusCode GetStatus() const { return error_message_; }

 private:
	StatusCode error_message_;

	
};

Request Get(int client_fd);
Request Parse(const std::string& raw);


}  // namespace ns_http

#endif  // NSHTTP_REQUEST_H_
