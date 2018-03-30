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
    QPen pen(Qt::DotLine);
    pen.setColor(QColor(255,0,0));
    QBrush brush(Qt::blue);
    brush.setStyle(Qt::HorPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(100,100,200,200);
}
Dialog::~Dialog()
{
    delete ui;
}
