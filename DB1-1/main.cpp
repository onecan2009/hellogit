#include <QCoreApplication>
#include <QtSql>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open())
    {
        return false;
        cout<<"Error in opening DB"<<endl;
    }
    cout<<"Successfully open DB"<<endl;
    QSqlQuery query;
    query.exec("create table student(id int primary key,name varchar)");
    query.exec("insert into student values(1,'xiaogang')");
    query.exec("insert into student values(2,'xiaoming')");
    query.exec("insert into student values(3,'xiaohong')");
    query.exec("select id,name from student where id >= 2");
    while(query.next())
    {
        int ele0 = query.value(0).toInt();
        QString ele1 =query.value(1).toString();
        qDebug() << ele0 <<ele1 ;
    }

    
    return a.exec();
}
