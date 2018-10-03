#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

enum Errors{
	INVALID_IP, INVALID_PORT, INVALID_STUDNR,
	SOCKET_FAIL, CONNECTION_FAIL, SEND_FAIL, READ_FAIL
};

class Socket{
public:
	Socket() : ip("158.36.70.56"), port(0), sock(0) {}
	void setIP(std::string i) {if(i!="lekeplass") ip = i;}
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
