#ifndef HTTP_REQUESTS_SOCKET_H
#define HTTP_REQUESTS_SOCKET_H

#include "Address.h"
#include "../Request/Request.h"
#include "../Response/Response.h"

class Socket {
public:
	virtual ~Socket() = default;

	static std::unique_ptr<Socket> create(const Http::Address& address);

	virtual bool connect() = 0;

	bool send(const Http::Request& request);
	Http::Response recv();

protected:
	virtual int send_raw(const std::string& data);
	virtual std::string recv_raw();
};


#endif //HTTP_REQUESTS_SOCKET_H
