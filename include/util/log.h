
#ifndef NSUTIL_LOG_H_
#define NSUTIL_LOG_H_

#include <string>

namespace ns_util {

class Log {
 public:
	static void Info(const std::string& msg);
	static void Error(const std::string& msg);
};

}  // namespace ns_util

#endif  // NSUTIL_LOG_H_
