
#ifndef NSHTTP_PIPELINE_QUEUE_H_
#define NSHTTP_PIPELINE_QUEUE_H_

#include <queue>

namespace ns_http {

class PipelineQueue {
 public:
	PipelineQueue();
	void Enqueue(const std::string& req);
	std::string Dequeue();
	// ...
};

}  // namespace ns_http

#endif  // NSHTTP_PIPELINE_QUEUE_H_
