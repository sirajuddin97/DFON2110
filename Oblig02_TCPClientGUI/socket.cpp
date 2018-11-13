#include "socket.h"

void Socket::makeConnection(std::string ip, int port){
    if(ip == "lekeplass") server.ip = "158.36.70.56"; else server.ip = ip;
    server.port = port;
    server.sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server.sock == 0) throw Server::SOCKET_ERROR;

    server.serv_addr.sin_addr.s_addr = inet_addr(server.ip.c_str());
    server.serv_addr.sin_family = AF_INET;
    server.serv_addr.sin_port = htons(server.port);
    int c = connect(server.sock, (struct sockaddr*)& server.serv_addr, sizeof(server.serv_addr));
    if(c < 0) throw Server::INVALID_CONNECTION;
    server.isConnected = true;
}

void Socket::abortConnection(){
    server.isConnected = false;
}
