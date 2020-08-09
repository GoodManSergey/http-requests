#ifndef HTTP_REQUESTS_LINUXSOCKET_H
#define HTTP_REQUESTS_LINUXSOCKET_H

#include <memory>
#include "Socket.h"
#include "Address.h"

#ifdef __linux__
#include <netinet/in.h>

class LinuxSocket: public Socket {
public:
	~LinuxSocket() override = default;
	bool connect() override;
	static std::unique_ptr<Socket> create(const Http::Address& addr);

private:
	LinuxSocket() = default;
	bool init(const Http::Address& addr);

	int m_fd;
	sockaddr_in m_addr;
};

#endif

#endif //HTTP_REQUESTS_LINUXSOCKET_H
