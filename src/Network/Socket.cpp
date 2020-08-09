#ifdef __linux__
#include "LinuxSocket.h"
#endif

#include "Socket.h"

std::unique_ptr<Socket> Socket::create(const Http::Address& address) {
#ifdef __linux__
	return std::move(LinuxSocket::create(address));
#endif
}