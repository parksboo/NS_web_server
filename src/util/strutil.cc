
// related header
#include "util/strutil.h"

// system header

// C++ standard library
#include <string>
#include <algorithm>

// project header

namespace ns_util {

std::string Trim(const std::string& s) {
  size_t start = s.find_first_not_of(" \t\r\n");
  size_t end = s.find_last_not_of(" \t\r\n");
  if (start == std::string::npos || end == std::string::npos) {
    return "";
  }
  return s.substr(start, end - start + 1);
}

std::string ToLower(std::string s) {
  std::transform(s.begin(), s.end(), s.begin(),
                 [](unsigned char c){ return std::tolower(c); });
  return s;
}

}  // namespace ns_util