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
    QPixmap pix;
    pix.load("C:\Sensor.jpg");
    painter.drawPixmap(0,0,100,100,pix);
    painter.translate(100,100);

    painter.drawPixmap(0,0,100,100,pix);
}

Dialog::~Dialog()
{
    delete ui;
}
