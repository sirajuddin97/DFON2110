#include "client.h"
#include "ui_client.h"

TCPClient::TCPClient(QWidget *parent) : QMainWindow(parent), ui(new Ui::TCPClient){
    ui->setupUi(this);
    ui->logBox->setReadOnly(true);
}

TCPClient::~TCPClient(){
    delete ui;
}

void TCPClient::on_connectButton_clicked(){
    ui->logBox->appendPlainText("TCPClient started!");
}
