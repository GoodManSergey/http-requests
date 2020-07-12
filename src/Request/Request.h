#ifndef HTTP_REQUESTS_REQUEST_H
#define HTTP_REQUESTS_REQUEST_H

#include "../HttpUtils/Method.h"
#include <string>

class Request {
public:
	Request();

	std::string m_version;
	Method m_method;

};


#endif //HTTP_REQUESTS_REQUEST_H
