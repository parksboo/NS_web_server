
#ifndef NSHTTP_RESPONSE_H_
#define NSHTTP_RESPONSE_H_

#include <string>

namespace ns_http {

class Response {
 public:
	Response();
	std::string ToString() const;
	// ...
};

}  // namespace ns_http

#endif  // NSHTTP_RESPONSE_H_
