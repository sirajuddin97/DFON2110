#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

enum Errors{
	INVALID_IP,
	INVALID_PORT,
	SOCKET_OPEN
};

class Socket{
public:
	Socket();
	~Socket();

	void connect();

private:
	int sockfd, srv_port, n;
	std::string srv_ip;
};