#include "messageinfo.h"
#include "ui_messageinfo.h"

MessageInfo::MessageInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageInfo)
{
    ui->setupUi(this);
}

MessageInfo::~MessageInfo()
{
    delete ui;
}

void MessageInfo::setSMS(QString pNumber, QString smsMessage, QTime time)
{
    ui->phoneNumber->setText(pNumber);
    ui->message->setText(smsMessage);
    ui->lRecievedTime->setText("hello");

}
