#include "client.h"

void Socket::createSocket(){
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
	char* studnr = new char[6];
	std::cout << "\nSkriv inn student nummeret ditt: ";
	std::cin >> studnr;
	if(strlen(studnr) != 6) throw INVALID_STUDNR;

	char msg_id = 0x01;
	char studnr_size = strlen(studnr);
	short msg_size = sizeof(msg_id) + strlen(studnr); // Big endian?? 

	memset(buffer, 0, bufferSize);
	memcpy(buffer, &msg_id, sizeof(msg_id));
	memcpy(buffer+1, &msg_size, sizeof(msg_size));
	memcpy(buffer+3, &studnr_size, sizeof(studnr_size));
	memcpy(buffer+4, studnr, strlen(studnr));

	const int stream_size = sizeof(msg_id) + sizeof(msg_size) + sizeof(studnr_size) + strlen(studnr);
	int s = send(sock, buffer, stream_size, 0);
	if(s < 0) throw SEND_FAIL;
}

void Socket::receiveData(){
	memset(buffer, 0, bufferSize);
	int r = recv(sock, buffer, bufferSize, 0);
	if(r < 0) throw READ_FAIL;
	std::cout << buffer << std::endl;
}
