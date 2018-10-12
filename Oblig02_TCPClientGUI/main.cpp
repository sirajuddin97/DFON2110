#include "client.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication gui(argc, argv);
    TCPClient tcp;
    tcp.show();

    return gui.exec();
}
