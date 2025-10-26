#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_cdt = new CountdownTimer(this);
    m_button = new QPushButton("Start", this);

    QWidget *widget = new QWidget(this);
    QGridLayout *layout = new QGridLayout;
    widget->setLayout(layout);

    layout->addWidget(m_cdt, 0, 1);
    layout->addWidget(m_button, 0, 2);

    connect(m_button, &QPushButton::clicked, m_cdt, &CountdownTimer::startStopCountdownTimer);
    connect(m_cdt, &CountdownTimer::countdownTimeOn, this, [&](bool cdtOn){
        m_button->setText(cdtOn ? "Stop" : "Start");
    });

    this->setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
