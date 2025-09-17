
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

	// (선택사항) enum을 문자열로 바꿔주는 헬퍼 함수도 함께 제공하면 좋습니다.
	#include <string_view>
	inline std::string_view to_string(StatusCode code) {
		switch (code) {
			case StatusCode::OK: return "OK";
			case StatusCode::NOT_FOUND: return "Not Found";
			case StatusCode::BAD_REQUEST: return "Bad Request";
			case StatusCode::FORBIDDEN: return "Forbidden";
			case StatusCode::METHOD_NOT_ALLOWED: return "Method Not Allowed";
			case StatusCode::HTTP_VERSION_NOT_SUPPORTED: return "HTTP Version Not Supported";
			
			default: return "Unknown Status Code";
		}
	}


}  // namespace ns_http

#endif  // NSHTTP_STATUS_CODES_H_
