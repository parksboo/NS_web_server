
#ifndef NSUTIL_STRUTIL_H_
#define NSUTIL_STRUTIL_H_

#include <string>

namespace ns_util {

class StrUtil {
 public:
	static std::string Trim(const std::string& s);
	static std::string ToUpper(const std::string& s);
};

}  // namespace ns_util

#endif  // NSUTIL_STRUTIL_H_
