#include "countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QGridLayout(this);
    m_timer = new QTimer(this);
    m_timer->setInterval(1'000);
    m_timeEdit = new QTimeEdit(this);
    m_timeEdit->setDisplayFormat("HH:mm:ss");
    m_timeEdit->setAlignment(Qt::AlignCenter);
    m_time = QTime(0, 0, 10);
    m_timeEdit->setTime(m_time);
    m_checkBox = new QCheckBox("Timer", this);
    m_layout->addWidget(m_checkBox, 0, 0, Qt::AlignCenter);
    m_layout->addWidget(m_timeEdit, 1, 0, Qt::AlignCenter);

    connect(m_timer, &QTimer::timeout, this, &CountdownTimer::updateCountdown);
    connect(m_timeEdit, &QTimeEdit::userTimeChanged, [&](QTime time){
        if (!m_timer->isActive())
        {
            m_time = time;
        }
    });
}

void CountdownTimer::startStopCountdownTimer()
{
    if (m_timer->isActive())
    {
        m_timer->stop();
        m_timeEdit->setTime(m_time);
        m_timeEdit->setReadOnly(false);
    }
    else
    {
        if (m_checkBox->isChecked())
        {
            m_timer->start();
            m_timeEdit->setReadOnly(true);
        }
    }
}

void CountdownTimer::updateCountdown()
{
    QTime currentTime{m_timeEdit->time()};
    if (currentTime > QTime(0, 0, 0))
    {
        m_timeEdit->setTime(currentTime.addSecs(-1));
    }
    else
    {
        m_timer->stop();
        m_timeEdit->setTime(m_time);
        m_timeEdit->setReadOnly(false);
        emit(finishedCountdown());
    }
}
