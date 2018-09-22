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
	READ_FAIL,
	INVALID_STUDNR
};

class Socket{
public:
	Socket() : port(0), sock(0) {};
	void setIP(std::string i) {ip = i;}
	void setPort(int p) {port = p;}
	void createSocket();
	void connectSocket();
	void sendData();
	void receiveData();

private:
	std::string ip;
	int port, sock;
	char buffer[1024];
	struct sockaddr_in serv_addr;
};
