#include "callinfo.h"
#include "ui_callinfo.h"

CallInfo::CallInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CallInfo)
{
    ui->setupUi(this);
}

CallInfo::~CallInfo()
{
    delete ui;
}

void CallInfo::setCall(QString pNumber, QString recievedTime)
{
    ui->lPhoneNumber->setText(pNumber);
    ui->lRecievedTime->setText(recievedTime);
}
