#ifndef MESSAGEINFO_H
#define MESSAGEINFO_H

#include <QWidget>
#include <QTime>

namespace Ui {
class MessageInfo;
}

class MessageInfo : public QWidget
{
    Q_OBJECT
    
public:
    explicit MessageInfo(QWidget *parent = 0);
    ~MessageInfo();
    void setSMS(QString pNumber, QString smsMessage, QString recievedTime);
    
private:
    Ui::MessageInfo *ui;
};

#endif // MESSAGEINFO_H
