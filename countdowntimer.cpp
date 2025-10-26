#include "countdowntimer.h"

CountdownTimer::CountdownTimer(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);
    m_timer = new QTimer(this);
    m_timer->setInterval(1'000);
    m_timeEdit = new QTimeEdit(this);
    m_timeEdit->setDisplayFormat("HH:mm:ss");
    m_timeEdit->setAlignment(Qt::AlignCenter);
    m_time = QTime(0, 0, 5);
    m_timeEdit->setTime(m_time);
    m_layout->addWidget(m_timeEdit);

    connect(m_timer, &QTimer::timeout, this, &CountdownTimer::updateCountdown);
    connect(m_timeEdit, &QTimeEdit::userTimeChanged, this, [&](QTime time){
        if (!m_timer->isActive())
        {
            m_time = time;
        }
    });
    this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

void CountdownTimer::startStopCountdownTimer()
{
    if (m_timer->isActive())
    {
        m_timer->stop();
        m_timeEdit->setTime(m_time);
    }
    else
    {
        m_timer->start();
    }
    emit(countdownTimeOn(m_timer->isActive()));
}

void CountdownTimer::updateCountdown()
{
    QTime currentTime{m_timeEdit->time()};
    if (currentTime > QTime(0, 0, 0))
    {
        m_timeEdit->setTime(currentTime.addSecs(-1));
    } else {
        m_timer->stop();
        m_timeEdit->setTime(m_time);
    }
    emit(countdownTimeOn(m_timer->isActive()));
}
