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
    QRectF ff(100,100,300,200);
    painter.drawRect(ff);
    painter.setPen(QColor(Qt::red));


    QFont font("arial",20,QFont::Bold,true);
    font.setUnderline(true);
    font.setOverline(true);
    font.setCapitalization(QFont::SmallCaps);
    font.setLetterSpacing(QFont::AbsoluteSpacing,5);
    QPainter painter1(this);
    painter1.setFont(font);
    painter1.setPen(QColor(Qt::red));
    painter1.drawText(ff,Qt::AlignHCenter,"ZMB University");
}

Dialog::~Dialog()
{
    delete ui;
}
