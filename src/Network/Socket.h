#ifndef HTTP_REQUESTS_SOCKET_H
#define HTTP_REQUESTS_SOCKET_H

#include "Address.h"

class Socket {
public:
	virtual ~Socket() = default;
	static virtual std::unique_ptr<Socket> create(const Http::Address& address);

	virtual bool connect() = 0;
};


#endif //HTTP_REQUESTS_SOCKET_H
