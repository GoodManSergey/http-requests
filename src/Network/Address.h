#ifndef HTTP_REQUESTS_ADDRESS_H
#define HTTP_REQUESTS_ADDRESS_H

#include <string>
#include <optional>
#include "../HttpUtils/Type.h"


namespace Http {

	class Address {
	public:
		enum class AddrFamily {
			IpV4,
			IpV6
		};

		static bool make_address(Address &address);

		Address() = default;

		std::optional<std::string> m_domain;
		std::optional<std::string> m_ip;
		std::optional<unsigned> m_port;
		std::optional<AddrFamily> m_addr_family;
		std::optional<Type> m_type;
	};

};

std::ostream& operator<<(std::ostream& os, const Http::Address::AddrFamily& value);

#endif //HTTP_REQUESTS_ADDRESS_H
