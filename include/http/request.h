
#ifndef NSHTTP_REQUEST_H_
#define NSHTTP_REQUEST_H_

#include <string>
#include <map>

namespace ns_http {

class Request {
 public:
    std::string method;
    std::string path;
    std::string version;
    std::map<std::string, std::string> headers;
	
	Request();
	
	std::string GetFileExtension();
	
	

};

Request Get(int client_fd);
Request Parse(const std::string& raw);


}  // namespace ns_http

#endif  // NSHTTP_REQUEST_H_
