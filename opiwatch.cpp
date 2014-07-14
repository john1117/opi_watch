#include "opiwatch.h"
#include "analogclock.h"
#include "messageinfo.h"
#include <QtDebug>
#include <QPushButton>
OpiWatch::OpiWatch(QWidget *parent) :
    QWidget(parent)
{

    analogClock = new AnalogClock(this);
    //analogClock->hide();
    messageInfo = new MessageInfo(this);
    messageInfo->hide();

    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    connect(tcpServer, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    tcpServer->listen(QHostAddress::Any, 8080);

    smsButton = new QPushButton(tr("sms"),analogClock);
    callButton = new QPushButton(tr("call"),analogClock);

    smsButton->setGeometry(0, 0, 30, 30);
    callButton->setGeometry(30,0, 30, 30);
    smsButton->setVisible(1);
    callButton->setVisible(1);
}

void OpiWatch::acceptConnection()
{
    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readTcpData()));

}

void OpiWatch::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_S) {
        analogClock->hide();
        messageInfo->show();
    } else if (event->key() == Qt::Key_C) {

    } else if (event->key() == Qt::Key_H) {
        messageInfo->hide();
        analogClock->show();
        messageInfo->setSMS("010-6293-1117", "hello odroid", analogClock->time);
    }


}

void OpiWatch::readTcpData()
{
    int i = 2;
    QByteArray buffer;
    QString temp = 0;
    QString temp2 = 0;
    buffer = tcpSocket->readLine();
    qDebug() << buffer;
    if (buffer[0] == 'n') {
        while (buffer[i] != 'e')
            temp += buffer[i++];
        i++;
        if (buffer[i] == 'm') {
            smsButton->setVisible(1);
            for (i += 1; i < buffer.size(); i++) {
                temp2 += buffer[i];
            }
            analogClock->hide();
            messageInfo->show();
            messageInfo->setSMS(temp, temp2, analogClock->time);
        } else if (buffer[i] == 's') {
            callButton->setVisible(1);
            if (buffer[i+1] == 'i') {
                //IDLE
            } else if (buffer[i+1] == 'r') {
                //RINGING
            }
            //temp2 = buffer[i];
            //messageInfo->hide();
            //analogClock->show();
            //messageInfo->setSms(temp, temp2);
        }
    }
}
