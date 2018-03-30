#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mydlg.h"
#include "widget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    myDlg my2;
    Ui::Widget *ui;
};

#endif // WIDGET_H
