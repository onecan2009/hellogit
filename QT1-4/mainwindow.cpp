#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isSaved = false;
    curFile = tr("Noname.txt");
    setWindowTitle(curFile);

}

void MainWindow::do_file_New()
{
    do_file_SaveOrNot();
    isSaved = false;
    curFile = tr("noname.txt");
    setWindowTitle(curFile);
    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
}

void MainWindow::do_file_SaveOrNot()
{
    if(ui->textEdit->document()->isModified())
    {
        QMessageBox box; box.setWindowTitle(tr("Waining"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr("Not saved, save?"));
        box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if(box.exec() == QMessageBox::Yes)
            do_file_Save();
    }
}

void MainWindow::do_file_Save()
{
    if(isSaved)
    {
        saveFile(curFile);
    }
    else
    {
        do_file_SaveAs();

    }
}

void MainWindow::do_file_SaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save as"),curFile);
    if(!fileName.isEmpty())
        saveFile(fileName);
}


bool MainWindow::saveFile(const QString& fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("Save file"), tr("Can not save file %1:\n %2").arg(fileName) .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    isSaved = true; curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_N_triggered()
{
    do_file_New();
}

void MainWindow::on_actionOpen_O_triggered()
{
    do_file_Open();
}

void MainWindow::on_actionSave_S_triggered()
{
    do_file_Save();
}

void MainWindow::on_actionSave_as_S_triggered()
{
    do_file_SaveAs();
}

void MainWindow::do_file_Open()//打开文件
{
    do_file_SaveOrNot();
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        do_file_Load(fileName);
    }
    ui->textEdit->setVisible(true);

}

bool MainWindow::do_file_Load(const QString& fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("Load file"),tr("Cannot load file%1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_actionClose_C_triggered()
{
    do_file_SaveOrNot();
    ui->textEdit->setVisible(false);
}

void MainWindow::on_actionExit_E_triggered()
{
    on_actionClose_C_triggered();
    qApp->quit();
}
