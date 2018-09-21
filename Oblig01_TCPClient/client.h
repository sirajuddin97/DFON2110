#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

enum Errors{
	INVALID_IP,
	INVALID_PORT,
	SOCKET_FAIL,
	CONNECTION_FAIL,
	SEND_FAIL,
	READ_FAIL
};

class Socket{
public:
	Socket();
	void createSocket();
	void connectSocket();
	void sendData();
	void receiveData();

private:
	std::string ip;
	int port;
	int sock;
	char buffer[1024];
	struct sockaddr_in serv_addr;
};
