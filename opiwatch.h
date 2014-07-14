#ifndef OPIWATCH_H
#define OPIWATCH_H

#include <QWidget>
#include <QtNetwork>
#include <QPushButton>
#include <QKeyEvent>

class AnalogClock;
class MessageInfo;

class OpiWatch : public QWidget
{
    Q_OBJECT
    
public:
    explicit OpiWatch(QWidget *parent = 0);
    QPushButton *smsButton;
    QPushButton *callButton;
protected:
    void keyPressEvent(QKeyEvent *);
    
private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    AnalogClock *analogClock;
    MessageInfo *messageInfo;

public slots:
    void acceptConnection();
    void readTcpData();
};

#endif // OPIWATCH_H
