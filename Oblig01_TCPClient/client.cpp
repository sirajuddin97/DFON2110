#include "client.h"

Socket::Socket(){
	//
}

Socket::~Socket(){
	//
}

void Socket::connect(){
	std::cout << "TCP SERVER CLIENT:\n";
	std::cout << "* Enter server IP address: ";
	std::cin >> srv_adr;
	if(!std::cin) throw INVALID_IP;
	std::cout << "* Enter server port: ";
	std::cin >> srv_port;
	if(!std::cin) throw INVALID_PORT;

	char buffer[256];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) throw SOCKET_OPEN;
}