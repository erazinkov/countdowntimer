#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QTimer>
#include <QTimeEdit>
#include <QCheckBox>

class CountdownTimer : public QWidget
{
    Q_OBJECT
public:
    CountdownTimer(QWidget *parent = nullptr);
signals:
    void stoppedCountdown();
    void finishedCountdown();
public slots:
    void startStopCountdownTimer();
private slots:
    void updateCountdown();
private:
    QGridLayout *m_layout;
    QTimer *m_timer;
    QTimeEdit *m_timeEdit;
    QTime m_time;
    QCheckBox *m_checkBox;
};

#endif // COUNTDOWNTIMER_H
