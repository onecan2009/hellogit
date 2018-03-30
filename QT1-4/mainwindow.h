#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <qfiledialog.h>
#include <QtGui>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_actionNew_N_triggered();

    void on_actionOpen_O_triggered();

    void on_actionSave_S_triggered();

    void on_actionSave_as_S_triggered();

    void on_actionClose_C_triggered();

    void on_actionExit_E_triggered();

private:
    Ui::MainWindow *ui;
    bool isSaved;
    QString curFile;
    void do_file_New();
    void do_file_SaveOrNot();
    void do_file_Save();
    void do_file_SaveAs();
    void do_file_Open();
    bool do_file_Load(const QString& fileName);
    bool saveFile(const QString& fileName);
};

#endif // MAINWINDOW_H
