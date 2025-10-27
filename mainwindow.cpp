#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_cdt = new CountdownTimer(this);
    m_button = new QPushButton("Start", this);
    m_button->setCheckable(true);


    QWidget *widget = new QWidget(this);
    QGridLayout *layout = new QGridLayout;
    widget->setLayout(layout);

    layout->addWidget(m_cdt, 0, 1);
    layout->addWidget(m_button, 0, 2);

    connect(m_button, &QPushButton::clicked, m_cdt, &CountdownTimer::startStopCountdownTimer);
    connect(m_button, &QPushButton::toggled, this, [&](bool checked){
        m_button->setText(checked ? "Stop" : "Start");
    });
    connect(m_cdt, &CountdownTimer::finishedCountdown, this, [&](){
        qDebug() << "Finished";
    });


    this->setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
    delete ui;
}
