#include "Request.h"

using namespace Http;

Request::Request() :
	m_version("1.1"),
	m_method(Method::GET)
{}