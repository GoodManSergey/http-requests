#include "Request/Request.h"
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include "Network/Address.h"


int main() {
	Request Requset{};
	auto hostname = gethostbyname(std::string("vk.com").c_str());
	std::cout << hostname->h_name << std::endl;
	for (int i = 0; hostname->h_addr_list[i] != 0; ++i) {
		struct sockaddr_in ssin;
		bcopy(hostname->h_addr_list[i], &ssin.sin_addr, hostname->h_length);
		std::cout << inet_ntoa(ssin.sin_addr) << std::endl;
		std::cout << ssin.sin_family;
	}
	struct sockaddr_in ssin;
	ssin.sin_port = 0;
	bcopy(hostname->h_addr, &ssin.sin_addr, hostname->h_length);
	ssin.sin_family = hostname->h_addrtype;
	std::cout << inet_ntoa(ssin.sin_addr) << std::endl;
	return 0;
}

