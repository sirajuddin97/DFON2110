#include "client.h"

int main(){
	try{
		Socket tcpClient;
		tcpClient.connect();
	}
	catch(Errors err){
		switch(err){
			case INVALID_IP: std::cout << "ERROR: Please enter a valid IP address!\n"; break;
			case INVALID_PORT: std::cout << "ERROR: Please enter a valid port number!\n"; break;
			case SOCKET_OPEN: std::cout << "ERROR: Could not open socket!\n"; break;
		}
	}
	catch(...){
		std::cout << "ERROR: Unknown error!\n";
	}
	return 0;
}