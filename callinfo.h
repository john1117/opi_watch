#ifndef CALLINFO_H
#define CALLINFO_H

#include <QWidget>

namespace Ui {
class CallInfo;
}

class CallInfo : public QWidget
{
    Q_OBJECT
    
public:
    explicit CallInfo(QWidget *parent = 0);
    ~CallInfo();
    void setCall(QString pNumber, QString recievedTime);
    
private:
    Ui::CallInfo *ui;
};

#endif // CALLINFO_H
