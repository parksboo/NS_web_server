#ifndef NSSERVER_CONN_MANAGER_H_
#define NSSERVER_CONN_MANAGER_H_

namespace ns_server {

class ConnManager {
 public:
	ConnManager();
	void Manage();

	// Non-copyable
	ConnManager(const ConnManager&) = delete;
	ConnManager& operator=(const ConnManager&) = delete;

	static ConnManager& GetInstance() {
		static ConnManager instance;
		return instance;
	}
};

}  // namespace ns_server

#endif  // NSSERVER_CONN_MANAGER_H_
