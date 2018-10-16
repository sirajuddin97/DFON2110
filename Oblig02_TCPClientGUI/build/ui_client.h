/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPClient
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *logBox;
    QLineEdit *ipBox;
    QPushButton *connectButton;
    QLineEdit *portBox;
    QPushButton *clearButton;
    QLabel *signature;

    void setupUi(QMainWindow *TCPClient)
    {
        if (TCPClient->objectName().isEmpty())
            TCPClient->setObjectName(QStringLiteral("TCPClient"));
        TCPClient->resize(750, 485);
        centralWidget = new QWidget(TCPClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logBox = new QPlainTextEdit(centralWidget);
        logBox->setObjectName(QStringLiteral("logBox"));
        logBox->setGeometry(QRect(10, 100, 731, 341));
        ipBox = new QLineEdit(centralWidget);
        ipBox->setObjectName(QStringLiteral("ipBox"));
        ipBox->setGeometry(QRect(230, 20, 141, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        ipBox->setFont(font);
        ipBox->setClearButtonEnabled(false);
        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(240, 60, 121, 32));
        portBox = new QLineEdit(centralWidget);
        portBox->setObjectName(QStringLiteral("portBox"));
        portBox->setGeometry(QRect(380, 20, 141, 31));
        portBox->setFont(font);
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(390, 60, 121, 32));
        signature = new QLabel(centralWidget);
        signature->setObjectName(QStringLiteral("signature"));
        signature->setGeometry(QRect(280, 460, 201, 20));
        TCPClient->setCentralWidget(centralWidget);

        retranslateUi(TCPClient);

        QMetaObject::connectSlotsByName(TCPClient);
    } // setupUi

    void retranslateUi(QMainWindow *TCPClient)
    {
        TCPClient->setWindowTitle(QApplication::translate("TCPClient", "TCPClient", nullptr));
        ipBox->setPlaceholderText(QApplication::translate("TCPClient", "IP address", nullptr));
        connectButton->setText(QApplication::translate("TCPClient", "Connect", nullptr));
        portBox->setPlaceholderText(QApplication::translate("TCPClient", "Port number", nullptr));
        clearButton->setText(QApplication::translate("TCPClient", "Clear console", nullptr));
        signature->setText(QApplication::translate("TCPClient", "<html><head/><body><p><span style=\" font-size:12pt;\">Coded with \342\235\244 by Sirajuddin Asjad</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPClient: public Ui_TCPClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
