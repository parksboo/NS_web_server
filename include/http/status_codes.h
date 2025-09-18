
#ifndef NSHTTP_STATUS_CODES_H_
#define NSHTTP_STATUS_CODES_H_

namespace ns_http {

	enum class StatusCode {
		OK = 200,
		BAD_REQUEST = 400,
		FORBIDDEN = 403,
		NOT_FOUND = 404,
		METHOD_NOT_ALLOWED = 405,
		HTTP_VERSION_NOT_SUPPORTED = 505
	};

}  // namespace ns_http

#endif  // NSHTTP_STATUS_CODES_H_
