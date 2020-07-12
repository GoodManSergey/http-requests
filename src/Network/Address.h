#ifndef HTTP_REQUESTS_ADDRESS_H
#define HTTP_REQUESTS_ADDRESS_H

#include <string>
#include <optional>
#include "../HttpUtils/Type.h"


class Address {
public:
	enum class AddrFamily {
		IpV4,
		IpV6
	};

	static void fill_address(Address& address);

	Address():
	m_type(Type::HTTP) {}

	std::optional<std::string> m_domain;
	std::optional<std::string> m_ip;
	std::optional<unsigned> m_port;
	std::optional<AddrFamily> m_addr_family;
	Type m_type;
};


#endif //HTTP_REQUESTS_ADDRESS_H
