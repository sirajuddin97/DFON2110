#include "client.h"

Socket::Socket(){
	port = 0;
	sock = 0;
}

void Socket::createSocket(){
	std::cout << "TCP SERVER CLIENT:\n";
	std::cout << "* Enter server IP address: ";
	std::cin >> ip;
	if(!std::cin) throw INVALID_IP;

	std::cout << "* Enter server port: ";
	std::cin >> port;
	if(!std::cin || port <= 0 || port > 9999) throw INVALID_PORT;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock == 0) throw SOCKET_FAIL;
}

void Socket::connectSocket(){
	std::cout << "STATUS: Connecting to " << ip << " on port " << port << "...\n";
	serv_addr.sin_addr.s_addr = inet_addr(ip.c_str());
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	int c = connect(sock, (struct sockaddr*)& serv_addr, sizeof(serv_addr));
	if(c < 0) throw CONNECTION_FAIL;
	std::cout << "STATUS: Successfully connected to the server!\n";
}

void Socket::sendData(){
	std::string student_nr;
	std::cout << "\nSkriv inn student nummeret ditt: ";
	std::cin >> student_nr;
	int s = send(sock, student_nr.c_str(), strlen(student_nr.c_str()), 0);
	if(s < 0) throw SEND_FAIL;
}

void Socket::receiveData(){
	int r = recv(sock, buffer, sizeof(buffer), 0);
	if(r < 0) throw READ_FAIL;
	std::cout << buffer << std::endl;
}
