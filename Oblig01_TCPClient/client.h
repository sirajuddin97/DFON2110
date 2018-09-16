#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class Socket{
public:
	Socket();
	~Socket();

	class err_open{};

	void connect();

private:
	int sockfd, srv_port, n;
	std::string srv_adr;
};

enum Errors{
	INVALID_IP,
	INVALID_PORT,
	SOCKET_OPEN
};