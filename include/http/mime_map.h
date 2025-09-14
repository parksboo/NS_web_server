
#ifndef NSHTTP_MIME_MAP_H_
#define NSHTTP_MIME_MAP_H_

#include <string>

namespace ns_http {

class MimeMap {
 public:
	static std::string GetMimeType(const std::string& ext);
};

}  // namespace ns_http

#endif  // NSHTTP_MIME_MAP_H_
