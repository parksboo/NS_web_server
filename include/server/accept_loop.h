
#ifndef NSSERVER_ACCEPT_LOOP_H_
#define NSSERVER_ACCEPT_LOOP_H_

namespace ns_server {

class AcceptLoop {
 public:
	AcceptLoop();
	void Run();
	// Non-copyable
	AcceptLoop(const AcceptLoop&) = delete;
	AcceptLoop& operator=(const AcceptLoop&) = delete;
};

}  // namespace ns_server

#endif  // NSSERVER_ACCEPT_LOOP_H_
