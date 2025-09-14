#ifndef NSSERVER_CONN_MANAGER_H_
#define NSSERVER_CONN_MANAGER_H_

namespace ns_server {

class ConnManager {
 public:
	ConnManager();
	void Manage();
	ConnManager(const ConnManager&) = delete;
	ConnManager& operator=(const ConnManager&) = delete;
};

}  // namespace ns_server

#endif  // NSSERVER_CONN_MANAGER_H_
