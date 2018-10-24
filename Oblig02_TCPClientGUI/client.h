#ifndef CLIENT_H
#define CLIENT_H
#include <QMainWindow>
#include <QDateTime>
#include "socket.h"

namespace Ui{
    class TCPClient;
}

class TCPClient : public QMainWindow{
    Q_OBJECT

public:
    explicit TCPClient(QWidget *parent = nullptr);
    ~TCPClient();

private slots:
    void on_connectButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::TCPClient *ui;
    void addLog(QString);
    Socket socket;
};

#endif
