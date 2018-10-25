#include "socket.h"

void Socket::makeConnection(std::string ip, int port){
	sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == 0) throw INVALID_CONNECTION;
	else isConnected = true;
}

void Socket::abortConnection(){
    isConnected = false;
}
