#include "Address.h"
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>

using namespace Http;

bool Address::make_address(Address &address) {
	if (!address.m_type) {
		address.m_type = Type::HTTP;
	}

	if (!address.m_port) {
		switch (*address.m_type) {
			case Type::HTTP:
				address.m_port = 80;
				break;
			case Type::HTTPS:
				address.m_port = 443;
				break;
		}
	}

	if (address.m_domain) {
		addrinfo hints;
		addrinfo *res;

		memset(&hints, 0, sizeof(hints));
		hints.ai_family = PF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		int errcode = getaddrinfo (address.m_domain->c_str(), NULL, &hints, &res);
		if (errcode != 0) {
			return false;
		}

		if (!res) {
			return false;
		}

		char addr_str[100];
		inet_ntop(res->ai_family, res->ai_addr->sa_data, addr_str, 100);

		void* ptr = nullptr;
		switch (res->ai_family)
		{
			case AF_INET:
				address.m_addr_family = AddrFamily::IpV4;
				ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
				break;
			case AF_INET6:
				address.m_addr_family = AddrFamily::IpV6;
				ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
				break;
		}

		inet_ntop (res->ai_family, ptr, addr_str, 100);
		address.m_ip = addr_str;


	} else if (!address.m_domain || !address.m_addr_family) {
		return false;
	}

	return true;
}
