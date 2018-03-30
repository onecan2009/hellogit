//#include <QCoreApplication>
#include <iostream>
#include<string.h>
#include <fstream>
#include <iomanip>

using namespace std;

class Student
{
public:
    Student(char* pS, unsigned num, float g)
    {
        strcpy(pName, pS);
        uID = num;
        grade = g;
    }
    virtual void display(ostream & out);
protected:
    char pName[20];
    unsigned int uID;
    float grade;

};
//ostream & operator<<(ostream& out, Student & st);

 void Student::display(ostream& out)
{
    out<<pName<<"    "<<uID<<"    "<<grade;
}

ostream& operator<<(ostream& out, Student& st)
{
    st.display(out);
    out<<endl;
    return out;
}

class MasterStudent: public Student
{
public:
    MasterStudent(char* pS, unsigned num, float g, char t):Student(pS, num, g)
    {type = t;}
    virtual void display(ostream &out);
protected:
    char type;
};

void MasterStudent::display(ostream &out)
{
    Student::display(out);
    out<<",  "<<type;
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    
   // {
        ofstream out1("C:\\bbc.txt");
        Student s1 ("Bill Gates",12567,3.5);
        MasterStudent s2("Bill Clinton", 12667, 4.1, 'A');
        MasterStudent s3("Oshikawa", 12579,3.8,'B');
        out1 << s1;
        cout<<"Write Stdent OBJ1"<<endl;
        out1 << s2;
        cout<<"Write Master Stdent OBJ1"<<endl;
        out1 << s3;
        cout<<"Write Master Stdent OBJ2"<<endl;
//    }
//   return a.exec();
}
