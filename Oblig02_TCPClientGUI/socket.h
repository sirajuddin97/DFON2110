#ifndef SOCKET_H
#define SOCKET_H
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
    Socket() : sock(0), port(0), ip("NULL"), isConnected(false) {}
    bool makeConnection(std::string, int);
    void abortConnection();
    bool getConnectionStatus() const{ return isConnected; }

private:
    int sock, port;
    std::string ip;
    bool isConnected;
    struct sockaddr_in serv_addr;
};

#endif
