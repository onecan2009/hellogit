#include "logindlg.h"
#include "ui_logindlg.h"
#include <QtGui>
#include <QMessageBox>

loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
    //added
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_loginBtn_clicked()
{
    //The whole part is added additional
    if(ui->usrEdit->text().trimmed()==tr("qt")&&ui->pwdEdit->text()==tr("123"))
        accept();
    else
    {
        QMessageBox::warning(this,tr("Warning"),tr("user name or password error!"),QMessageBox::Yes);
        ui->usrEdit->clear();
        ui->pwdEdit->clear();
        ui->usrEdit->setFocus();
    }
}
