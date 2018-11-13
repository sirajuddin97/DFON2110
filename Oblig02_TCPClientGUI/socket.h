#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

namespace Server{
    struct serverInfo{
        int sock, port;
        std::string ip;
        bool isConnected;
        sockaddr_in serv_addr;
    };

    struct studentInfo{
        char* number = new char[6];
        int size = sizeof(number);
    };

    enum class MessageID{
        REQUEST_PORT = 0x01,
        RECEIVE_PORT = 0x02,
        PING = 0x03,
        PONG = 0x04,
        ABORT = 0x05
    };

    enum Errors{
        SOCKET_ERROR,
        INVALID_CONNECTION
    };
};

class Socket{
public:    
    //Socket() : server{ 0, 0, "NULL", false } {}
    Socket(){
        server.sock = 0;
        server.port = 0;
        server.ip = "NULL";
    }
    void makeConnection(std::string, int);
    void abortConnection();
    bool getConnectionStatus() const{ return server.isConnected; }
    char* getStudentNumber() const{ return student.number; }

private:
    Server::serverInfo server;
    Server::studentInfo student;
};

#endif
