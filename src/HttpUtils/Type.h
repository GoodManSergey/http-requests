#ifndef HTTP_REQUESTS_TYPE_H
#define HTTP_REQUESTS_TYPE_H

#include <iostream>

namespace Http {

	enum class Type: int {
		HTTP,
		HTTPS
	};

};

std::ostream& operator<<(std::ostream& os, const Http::Type& value);

#endif //HTTP_REQUESTS_TYPE_H
