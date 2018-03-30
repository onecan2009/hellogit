#include <QCoreApplication>
#include <iostream>
using namespace std;

class Student
{
public:
    Student(string &str);
    ~Student();
    //static showName() {cout << name <<endl;}
    void showName(){ cout << name << endl;}
    static Student* getHeader(){return pFirst;}
    static Student* pFirst;
    static int noOfstudent;
    Student *pNext;
    string name;
};
Student::Student(string & str)
{
    name = str;
    pNext = NULL;
    noOfstudent++;
    cout << noOfstudent <<endl;
    //新结点加入链表头
    if(pFirst == NULL)
    {
        pFirst = this;
    }
    else
    {
        pNext = pFirst;
        pFirst = this;
    }
}
Student::~Student()
{
    if(NULL==pNext)
        delete pNext;
    noOfstudent--;
}

Student * Student::pFirst = NULL;
int Student::noOfstudent = 0;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        int n = 5;
        //创建链表
        for(int i = 0; i < n; i++)
        {
            string name;
            cout << "name: ";
            cin >> name;
            Student *pt = new Student(name);
        }
        //打印
        Student *p = Student::getHeader();
        while(p)
        {
            p->showName();
            p = p->pNext;
        }
        //释放链表
        if(Student::pFirst)
            delete Student::pFirst;
    }
    return a.exec();
}
