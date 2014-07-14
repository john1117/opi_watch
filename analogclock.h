#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QTime>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    explicit AnalogClock(QWidget *parent = 0);
    QTimer *timer;
    QTime time;

protected:
    void paintEvent(QPaintEvent *event);
private:
};

#endif // ANALOGCLOCK_H
