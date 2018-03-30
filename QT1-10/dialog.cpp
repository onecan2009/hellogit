#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QLinearGradient linearGradient(100,150,300,150);
    linearGradient.setColorAt(0,Qt::red);
    linearGradient.setColorAt(0.2,Qt::black);
    linearGradient.setColorAt(0.4,Qt::yellow);
    linearGradient.setColorAt(0.6,Qt::white);
    linearGradient.setColorAt(0.8,Qt::green);
    linearGradient.setColorAt(1,Qt::blue);
    painter.setBrush(linearGradient);
    painter.drawRect(100,100,200,100);
}

Dialog::~Dialog()
{
    delete ui;
}
