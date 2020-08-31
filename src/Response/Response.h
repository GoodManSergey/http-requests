#ifndef HTTP_REQUESTS_RESPONSE_H
#define HTTP_REQUESTS_RESPONSE_H

#include <string>
#include <unordered_map>
#include "../HttpUtils/Status.h"

namespace Http {

	class Response {
	public:
		Response();

		Http::StatusCode m_status_code;
		std::unordered_map<std::string, std::string> m_headers;
		std::string m_content;
	};

}

#endif //HTTP_REQUESTS_RESPONSE_H
