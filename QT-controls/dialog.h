#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "person.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_saveBtn_clicked();

    void on_loadBtn_clicked();

    void on_abortBtn_clicked();

private:
        Person p2;
        Person p1;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
