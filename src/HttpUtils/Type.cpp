#include "Type.h"


std::ostream& operator<<(std::ostream& os, const Http::Type& value) {
	switch (value) {
		case Http::Type::HTTP:
			os << "http";
			break;
		case Http::Type::HTTPS:
			os << "https";
			break;
	}
	return os;
}