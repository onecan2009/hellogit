#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    void mouseMoveEvent(QMouseEvent *m);
    void keyPressEvent(QKeyEvent *k);
    //void mouseReleaseEvent(QMouseEvent *);
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
};

#endif // DIALOG_H
