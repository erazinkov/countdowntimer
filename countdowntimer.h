#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QTimeEdit>

class CountdownTimer : public QWidget
{
    Q_OBJECT
public:
    CountdownTimer(QWidget *parent = nullptr);
signals:
    void isCountdownOn(bool);
public slots:
    void startStopCountdownTimer();
private slots:
    void updateCountdown();
private:
    QHBoxLayout *m_layout;
    QTimer *m_timer;
    QTimeEdit *m_timeEdit;
    QTime m_time;
};

#endif // COUNTDOWNTIMER_H
