#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    timer->start(1000);
    startTimer(1000);
    startTimer(5000);
    startTimer(10000);

}

void MainWindow::timerEvent(QTimerEvent *t)
{ switch(t->timerId())
    {
    case 1 : ui->label->setText(tr("One rand per second %1").arg(qrand()%10));
        break;
    case 2 : ui->label_2->setText(tr("close in 5 seconds"));
        break;
    case 3 : qApp->quit();
        break;
    }
}

void MainWindow::timerUpDate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
