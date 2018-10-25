#include "client.h"
#include "ui_client.h"

TCPClient::TCPClient(QWidget *parent) : QMainWindow(parent), ui(new Ui::TCPClient){
    ui->setupUi(this);
}

TCPClient::~TCPClient(){
    delete ui;
}

void TCPClient::addLog(QString text){
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("hh:mm:ss");
    ui->logBox->appendPlainText("[" + dateTimeString + "] " + text);
}

void TCPClient::on_connectButton_clicked(){
    if(!ui->ipBox->text().isEmpty() && !ui->portBox->text().isEmpty()){
        std::string tempIP = ui->ipBox->text().toStdString();
        int tempPort = ui->ipBox->text().toInt();

        if(!socket.getConnectionStatus()){
			try{
                socket.makeConnection(tempIP, tempPort);
                addLog("Successfully connected to the server!");
                ui->connectButton->setText("Disconnect");
			}
            catch(Errors e){
                switch(e){
                    case INVALID_CONNECTION: addLog("Failed to connect to the server. Try again!"); break;
                }
            }
            catch(...){ addLog("Unknown error occured!"); }
        }
        else{
            socket.abortConnection();
            addLog("Disconnected from the server!");
            ui->connectButton->setText("Connect");
        }
    }
    else addLog("Please enter the server IP address and port number!");
}

void TCPClient::on_clearButton_clicked(){
    ui->logBox->clear();
}
