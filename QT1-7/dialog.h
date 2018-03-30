#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QMouseEvent>
#include "qpainter.h"
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

    ~Dialog();
    
private:
    Ui::Dialog *ui;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
    int scale;
    QPushButton *pushBtn;
private slots:
    void zoomIn();
};

#endif // DIALOG_H
