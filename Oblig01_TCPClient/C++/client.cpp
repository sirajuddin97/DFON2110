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
	const int msgSize = 10;
	std::string student_nr;
	std::cout << "\nSkriv inn student nummeret ditt: ";
	std::cin >> student_nr;
	if(strlen(student_nr.c_str()) != 6) throw INVALID_STUDNR;
	
	memset(buffer, 0, bufferSize);
	//char test = 0x01;
	//short test2 = 7;
	//char msg = 6;
	
	buffer[0] = 0x01; // Melding ID
	buffer[1] = 0; // Size of message (Big endian)
	buffer[2] = 7; // Size of message (Big endian)
	buffer[3] = 6; // Size of studentnr
	//buffer[4] = '2';
	//buffer[5] = '1';
	//buffer[6] = '6';
	//buffer[7] = '9';
	//buffer[8] = '8';
	//buffer[9] = '8';

	//memcpy(buffer, &test, sizeof(test));
	//memcpy(buffer+2, &test2, sizeof(test2));
	//memcpy(buffer+3, &msg, sizeof(msg));

	std::string studentID = "216988";

//	char* studentID = "216988";
    memcpy(buffer + 4, stu, 6);

	//memcpy(buffer+4, &student_nr, strlen(student_nr.c_str()));

	int s = send(sock, buffer, msgSize, 0);
	//int s = send(sock, student_nr.c_str(), strlen(student_nr.c_str()), 0);
	if(s < 0) throw SEND_FAIL;
}

void Socket::receiveData(){
	memset(buffer, 0, 1024);
	int r = recv(sock, buffer, sizeof(buffer), 0);
	if(r < 0) throw READ_FAIL;
	std::cout << buffer << std::endl;
}
