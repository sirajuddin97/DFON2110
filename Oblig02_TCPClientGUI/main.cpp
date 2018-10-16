#include "client.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    TCPClient client;
    client.show();

    return a.exec();
}
