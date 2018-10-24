#include "socket.h"

bool Socket::makeConnection(std::string ip, int port){
    isConnected = true;
    return true;
}

void Socket::abortConnection(){
    isConnected = false;
}
