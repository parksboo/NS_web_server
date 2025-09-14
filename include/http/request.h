
#ifndef NSHTTP_REQUEST_H_
#define NSHTTP_REQUEST_H_

#include <string>

namespace ns_http {

class Request {
 public:
	Request();
	bool Parse(const std::string& raw);
	// ...
};

}  // namespace ns_http

#endif  // NSHTTP_REQUEST_H_
