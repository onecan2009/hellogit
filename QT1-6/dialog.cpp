#include "dialog.h"
#include "ui_dialog.h"
#include <QtGui>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    ui->label->setText(tr("Please push A key"));
    ui->pushButton->setText(tr("Please push mouse"));
}


void Dialog::mouseMoveEvent(QMouseEvent *m)
{
    QCursor my(QPixmap("C:/Icon1.gif"));
    QApplication::setOverrideCursor(my);
    int x = m->pos().x();
    int y = m->pos().y();
    ui->pushButton->setText(tr("Current mouse pos is (%1,%2) is it funny").arg(x).arg(y));
    ui->pushButton->move(m->pos());
}

void Dialog::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_A)
    {
        ui->label->setPixmap(QPixmap("C:/Icon2.gif"));
        ui->label->resize(100,100);
    }
}

Dialog::~Dialog()
{
    delete ui;
}


