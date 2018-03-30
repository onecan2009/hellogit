#include "dialog.h"
#include "ui_dialog.h"

#include <QtGui>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    p2.setName("ZhangSanFeng");
    p2.setAge(25);
    p2.setGender(true);
    p2.setCity("Beijing");
    p2.setDistrict("Haidian");
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_loadBtn_clicked()
{
    ui->nameEdit->setText(p2.getName())  ;
    ui->ageEdit->setText(QString::number(p2.getAge()));

    ui->maleRadio->setChecked(p2.getGender());
    ui->femaleRadio->setChecked(!p2.getGender());

    ui->comboBox->addItem(p2.getCity());
    ui->listWidget->addItem(p2.getDistrict());

}

void Dialog::on_saveBtn_clicked()
{
    p1.setAge(ui->ageEdit->text().toInt());
    p1.setName(ui->nameEdit->text());
    p1.setGender(ui->maleRadio->isChecked());
    ui->listWidget->setFocus();
    p1.setCity(ui->comboBox->currentText());

    p1.setDistrict(ui->listWidget->currentItem()->text());

}

void Dialog::on_abortBtn_clicked()
{
    //accept();
    close();
}
