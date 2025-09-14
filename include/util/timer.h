
#ifndef NSUTIL_TIMER_H_
#define NSUTIL_TIMER_H_

namespace ns_util {

class Timer {
 public:
	Timer();
	void Reset();
	double Elapsed() const;
};

}  // namespace ns_util

#endif  // NSUTIL_TIMER_H_
