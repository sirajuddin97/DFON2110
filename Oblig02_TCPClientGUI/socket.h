#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

enum Errors{
    INVALID_CONNECTION
};

class Socket{
public:
    Socket() : sock(0), port(0), ip("NULL"), isConnected(false) {}
    void makeConnection(std::string, int);
    void abortConnection();
    bool getConnectionStatus() const{ return isConnected; }

private:
    int sock, port;
    std::string ip;
    bool isConnected;
    struct sockaddr_in serv_addr;
};

#endif
