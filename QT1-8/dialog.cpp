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
    //QPainter painter(this);
    //painter.drawLine(0,0,100,100);

    QPainter painter(this);
    QPen pen; //
    pen.setColor(QColor(255,0,0));
    QBrush brush(QColor(0,255,0,125)); //
    painter.setPen(pen); //
    painter.setBrush(brush); //
    painter.drawRect(100,100,200,200); //
}


Dialog::~Dialog()
{
    delete ui;
}
