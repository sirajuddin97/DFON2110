#include "client.h"

int main(){
	try{
		Socket tcpClient;
		tcpClient.createSocket();
		tcpClient.connectSocket();
		tcpClient.sendData();
		tcpClient.receiveData();
	}
	catch(Errors err){
		switch(err){
			case INVALID_IP: std::cout << "ERROR: Please enter a valid IP address!\n"; break;
			case INVALID_PORT: std::cout << "ERROR: Please enter a valid port number!\n"; break;
			case SOCKET_FAIL: std::cout << "ERROR: Could not create socket!\n"; break;
			case CONNECTION_FAIL: std::cout << "ERROR: Could not connect to the server!\n"; break;
			case SEND_FAIL: std::cout << "ERROR: Failed to send data!\n"; break;
			case READ_FAIL: std::cout << "ERROR: Failed to receive data!\n"; break;
		}
	}
	catch(...){
		std::cout << "ERROR: Unknown error!\n";
	}
	return 0;
}