#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void timerEvent(QTimerEvent *);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
private slots: void timerUpDate();
};

#endif // MAINWINDOW_H
