#include "dialog.h"
#include "ui_dialog.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    resize(600,500);
    pix = QPixmap(200,200);
    pix.fill(Qt::white);

    scale =1;
    pushBtn = new QPushButton(this);
    pushBtn->setText(tr("zoomIn"));
    pushBtn->move(500,450);
    connect(pushBtn,SIGNAL(clicked()),this,SLOT(zoomIn()));
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);
    //pp.drawLine(lastPoint,endPoint);
    pp.drawLine(lastPoint/scale,endPoint/scale);
    lastPoint = endPoint;
    QPainter painter(this);
    painter.scale(scale,scale);
    painter.drawPixmap(0,0,pix);
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
        lastPoint = event->pos();
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton)
    {
        endPoint = event->pos();
        update();
    }
}

void Dialog::zoomIn()
{
    scale *=2;
    update();
}

Dialog::~Dialog()
{
    delete ui;
}
