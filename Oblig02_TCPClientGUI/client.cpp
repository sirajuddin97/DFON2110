#include "client.h"
#include "ui_client.h"

TCPClient::TCPClient(QWidget *parent) : QMainWindow(parent), ui(new Ui::TCPClient){
    ui->setupUi(this);
    ui->logBox->setReadOnly(true);
}

TCPClient::~TCPClient(){
    delete ui;
}

QString TCPClient::getTime(){
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("hh:mm:ss");
    return dateTimeString;
}

void TCPClient::addLog(QString text){
    ui->logBox->appendPlainText("[" + getTime() + "] " + text);
}

void TCPClient::on_connectButton_clicked(){
    QString tempIP = ui->ipBox->text(), tempPort = ui->portBox->text();
    if(tempIP != "" && tempPort != ""){
        addLog("Connecting to " + tempIP + " on port " + tempPort + "...");
        ui->connectButton->setText("Disconnect");
    }
    else addLog("Please enter the server IP address and port number!");
}

void TCPClient::on_clearButton_clicked(){
    ui->logBox->clear();
}
