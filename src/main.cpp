#include "Request/Request.h"
#include <iostream>
#include "Network/Address.h"

int main (void)
{
	Http::Address addr;
	addr.m_domain = "m.vk.com";
	if (Http::Address::make_address(addr)) {
		std::cout << *addr.m_ip;
	}
	return EXIT_SUCCESS;
}

