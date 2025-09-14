#ifndef NSFS_DOCROOT_H_
#define NSFS_DOCROOT_H_

#include <string>

namespace ns_fs {

class DocRoot {
 public:
	explicit DocRoot(const std::string& root);
	std::string Resolve(const std::string& path) const;
};

}  // namespace ns_fs

#endif  // NSFS_DOCROOT_H_
