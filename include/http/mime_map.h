
#ifndef NSHTTP_MIME_MAP_H_
#define NSHTTP_MIME_MAP_H_

#include <string>
#include <unordered_map>

namespace ns_http {

class MimeMap {
 public:
	static std::string GetMimeType(const std::string& ext);
	static const std::unordered_map<std::string, std::string> mime_map;
};

}  // namespace ns_http

#endif  // NSHTTP_MIME_MAP_H_
