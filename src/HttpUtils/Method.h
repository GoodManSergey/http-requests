#ifndef CPP_WEB_METHOD_H
#define CPP_WEB_METHOD_H

#include <iostream>

namespace Http {

	enum class Method : int {
		GET,
		POST,
		PUT,
		DELETE
	};

};

std::ostream& operator<<(std::ostream& os, const Http::Method& value);

#endif //CPP_WEB_METHOD_H
