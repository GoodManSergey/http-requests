#include "LinuxSocket.h"

#ifdef __linux__
#include <arpa/inet.h>

bool LinuxSocket::init(const Http::Address& address) {
	sockaddr_in addr;
	if (!address.m_addr_family || !address.m_ip || !address.m_port)
		return false;

	if (*address.m_addr_family == Http::Address::AddrFamily::IpV4)
		addr.sin_family = AF_INET;
	if (*address.m_addr_family == Http::Address::AddrFamily::IpV6)
		addr.sin_family = AF_INET6;

	addr.sin_port = htons(*address.m_port);
	inet_aton(address.m_ip->c_str(), &addr.sin_addr);
	m_fd = socket(addr.sin_family, SOCK_STREAM, 0);
	m_addr = addr;
	return true;
}

bool LinuxSocket::connect() {
	return ::connect(m_fd, (sockaddr*)&m_addr, sizeof(m_addr)) < 0;
}

std::unique_ptr<Socket> LinuxSocket::create(const Http::Address &addr) {
	struct LinuxSocketFriend: public LinuxSocket{};
	std::unique_ptr<LinuxSocketFriend> socket = std::make_unique<LinuxSocketFriend>();

	if (socket->init(addr))
		return std::move(socket);
	else
		return {};
}

#endif