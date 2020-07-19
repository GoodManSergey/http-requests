#include "Request/Request.h"
#include <iostream>
#include "Network/Address.h"

int main ()
{
	Http::Address addr;
	addr.m_domain = "m.vk.com";
	if (Http::Address::make_address(addr)) {
		std::cout << "Ip: " << *addr.m_ip << std::endl;
		std::cout << "Type: " << *addr.m_type << std::endl;
		std::cout << "Addr Family: " << *addr.m_addr_family << std::endl;
	}
	return EXIT_SUCCESS;
}