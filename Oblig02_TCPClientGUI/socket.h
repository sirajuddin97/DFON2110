#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

namespace states{
    enum class MessageID{
        REQUEST_PORT = 0x01,
        RECEIVE_PORT = 0x02,
        PING = 0x03,
        PONG = 0x04,
        ABORT = 0x05
    };

    enum Errors{
        INVALID_CONNECTION
    };
};

namespace server{
    struct serverInfo{
        int sock, port;
        std::string ip;
        bool isConnected;
        struct sockaddr_in serv_addr;
    };

    struct studentInfo{
        char* number = new char[6];
        int size = sizeof(number);
    };
};

class Socket{
public:
    //Socket() : serv.sock(0), serv.port(0), serv.ip("NULL"), serv.isConnected(false) {}

    Socket(){
        srv.sock = 0;
        srv.port = 0;
        srv.ip = "NULL";
        srv.isConnected = false;
    }

    void makeConnection(std::string, int);
    void abortConnection();
    bool getConnectionStatus() const{ return srv.isConnected; }
    char* getStudentNumber() const{ return stud.number; }

private:
    server::serverInfo srv;
    server::studentInfo stud;
};

#endif
