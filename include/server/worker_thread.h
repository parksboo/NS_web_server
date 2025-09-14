
#ifndef NSSERVER_WORKER_THREAD_H_
#define NSSERVER_WORKER_THREAD_H_

namespace ns_server {

class WorkerThread {
 public:
	WorkerThread();
	void Start();
	WorkerThread(const WorkerThread&) = delete;
	WorkerThread& operator=(const WorkerThread&) = delete;
};

}  // namespace ns_server

#endif  // NSSERVER_WORKER_THREAD_H_
