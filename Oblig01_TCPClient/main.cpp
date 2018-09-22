#include "client.h"

int main(){
	try{
		Socket tcpClient;
		std::string newIP; int newPort;
		std::cout << "TCP SERVER CLIENT:\n";
		std::cout << "* Enter server IP address: ";
		std::cin >> newIP; if(!std::cin) throw INVALID_IP; else tcpClient.setIP(newIP);
		std::cout << "* Enter server port: ";
		std::cin >> newPort; if(!std::cin || newPort <= 0 || newPort > 9999) throw INVALID_PORT; else tcpClient.setPort(newPort);
		tcpClient.createSocket();
		tcpClient.connectSocket();
		tcpClient.sendData();
		tcpClient.receiveData();
	}
	catch(Errors err){
		switch(err){
			case INVALID_IP: std::cerr << "ERROR: Please enter a valid IP address!\n"; break;
			case INVALID_PORT: std::cerr << "ERROR: Please enter a valid port number!\n"; break;
			case SOCKET_FAIL: std::cerr << "ERROR: Could not create socket!\n"; break;
			case CONNECTION_FAIL: std::cerr << "ERROR: Could not connect to the server!\n"; break;
			case SEND_FAIL: std::cerr << "ERROR: Failed to send data!\n"; break;
			case READ_FAIL: std::cerr << "ERROR: Failed to receive data!\n"; break;
			case INVALID_STUDNR: std::cerr << "ERROR: Student number must contain 6 digits!\n"; break;
		}
	}
	catch(...){
		std::cout << "ERROR: Unknown error!\n";
	}
	return 0;
}
