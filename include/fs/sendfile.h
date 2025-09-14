
#ifndef NSFS_SENDFILE_H_
#define NSFS_SENDFILE_H_

#include <string>

namespace ns_fs {

class SendFile {
 public:
	static bool Send(int fd, const std::string& path);
};

}  // namespace ns_fs

#endif  // NSFS_SENDFILE_H_
