#ifndef MYDLG_H
#define MYDLG_H

#include <QDialog>

namespace Ui {
class myDlg;
}

class myDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit myDlg(QWidget *parent = 0);
    ~myDlg();
    
private slots:
    void on_enterBtn_clicked();

private:
    Ui::myDlg *ui;
};

#endif // MYDLG_H
