#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>

namespace Ui{
    class TCPClient;
}

enum Errors{
	INVALID_IP, INVALID_PORT, INVALID_STUDNR,
	SOCKET_FAIL, CONNECTION_FAIL, SEND_FAIL, READ_FAIL
};


class Socket{
public:
	Socket();
	void setIP(std::string i){if(i!="lekeplass") ip = i;}
	void setPort(int p){port = p;}

private:
    std::string ip;
	int port;
	int sock;
    //struct sockaddr_in serv_addr;
};


class TCPClient : public QMainWindow{
    Q_OBJECT

public:
    explicit TCPClient(QWidget *parent = nullptr);
    ~TCPClient();

private slots:
    void on_connectButton_clicked();

private:
    Ui::TCPClient *ui;

	void createSocket();
	void connectSocket();
	void sendData();
	void receiveData();

	static const int bufferSize = 512;
	char buffer[bufferSize];
};

#endif
