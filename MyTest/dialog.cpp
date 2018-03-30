#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

#include </home/zm/Qt5.4.1/5.4/gcc/include/QtSql/qsqldatabase.h>
#include </home/zm/Qt5.4.1/5.4/gcc/include/QtSql/qsqlquery.h>


//mysqlconnector

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_m_btn_clicked()
{
    //cd bin directory, mysql -u root -p;
    try
    {
         QSqlDatabase db =QSqlDatabase::addDatabase("QMYSQL");
         db.setUserName("root");
         db.setPassword("root");
         db.setHostName("localhost");
         db.setDatabaseName("world");
         db.setConnectOptions("CLIENT_SSL=1;CLIENT_IGNORE_SPACE=1");
         db.setPort(3306);
         db.open();
         if(db.isOpen())
         {

         QSqlQuery myquery;
         myquery.exec("select * from country");

         myquery.next();
         QString s = myquery.value(2).toString();
         int i = 0;
         }

     }
    catch(...)
     {
          QMessageBox::about(this,tr("msgbox"),tr("error"));
     }
    //ui->m_psw->setEchoMode(QLineEdit::Password);
    //if(ui->listWidget->currentItem()->text() == tr("hello"))
    //{

         //QMessageBox::about(this,tr("msgbox"),tr("checked"));
    //}
    /*if(ui->m_combo->currentText()==tr("guangzhou"))
    {
        QMessageBox::about(this,tr("msgbox"),tr("OK"));
    }*/
    /*ui->m_rd1->setChecked(true);
    if(ui->m_rd1->isChecked()==true)
    {
        QMessageBox::about(this,tr("msgbox"),tr("checked"));
    }*/
    /*if(ui->m_text->toPlainText()== tr("123"))
    {
        ui->m_btn->setText("OK");
     }
    else
    {
        ui->m_btn->setText("Wrong");
        QMessageBox::about(this,tr("msgbox"),tr("Wrong"));
    }*/
}
