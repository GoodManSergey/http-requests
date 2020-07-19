#include "Method.h"


std::ostream& operator<<(std::ostream& os, const Http::Method& value) {
	switch (value) {
		case Http::Method::GET:
			os << "get";
			break;
		case Http::Method::POST:
			os << "post";
			break;
		case Http::Method::PUT:
			os << "put";
			break;
		case Http::Method::DELETE:
			os << "delete";
			break;
	}

	return os;
}

