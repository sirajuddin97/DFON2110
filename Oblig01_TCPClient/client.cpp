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
	std::cin >> srv_ip;
	if(!std::cin) throw INVALID_IP;
	std::cout << "* Enter server port: ";
	std::cin >> srv_port;
	if(!std::cin || srv_port <= 0 || srv_port > 9999) throw INVALID_PORT;
	std::cout << "\nConnecting to " << srv_ip << ":" << srv_port << ", please wait...\n";

	char buffer[256];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) throw SOCKET_OPEN;
}