#include "Status.h"

using namespace Http;

std::optional<StatusCode> get_code(const std::string& code) {
	if (code == "200")
		return StatusCode::S200;
	else
		return {};
}
