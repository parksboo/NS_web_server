// related header
#include "http/mime_map.h"

// system header
#include <sys/types.h>

// C++ standard library
#include <string>
#include <unordered_map>

// project header


namespace ns_http {


const std::unordered_map<std::string, std::string> MimeMap::mime_map = {
    { "html", "text/html" },
    { "txt", "text/plain" },
    { "png", "image/png" },
    { "gif", "image/gif" },
    { "jpg", "image/jpeg" },
    { "css", "text/css" },
    { "ico", "image/x-icon" },
    { "js", "application/javascript" },
};

std::string MimeMap::GetMimeType(const std::string& ext) {
    auto it = mime_map.find(ext);
    if (it != mime_map.end()) {
        return it->second;
    }
    return "application/octet-stream";  // Default MIME type
}

}  // namespace ns_http
