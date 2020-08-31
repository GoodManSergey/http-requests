#ifndef HTTP_REQUESTS_PARSER_H
#define HTTP_REQUESTS_PARSER_H

#include <string>
#include <optional>
#include "Status.h"

namespace Http {

	static std::optional<StatusCode> parse_response_line(const std::string& line);
	static std::optional<std::pair<std::string, std::string>> parse_header(const std::string& header_line);
}


#endif //HTTP_REQUESTS_PARSER_H
