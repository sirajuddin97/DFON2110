#include "socket.h"

void Socket::makeConnection(std::string ip, int port){
    srv.sock = socket(AF_INET, SOCK_STREAM, 0);
    if(srv.sock == 0) throw states::INVALID_CONNECTION;
    else srv.isConnected = true;
}

void Socket::abortConnection(){
    srv.isConnected = false;
}
