#include <QCoreApplication>
#include <iostream>
using namespace std;

class Person {
 private:
     char* _name;
     int _id;
     int name_size;
public:
     Person(): _name(NULL), _id(0), name_size(0){}
     Person(const Person & p);
     Person & operator=(Person & p);
     void setId(int id){_id = id;}
     void showId(){cout << _id << endl;}
     void setName(char *sName);
     void showName();
};

Person & Person::operator=(Person & p)
{
    cout << "operator= !" << endl;
    if(NULL != _name && strlen(p._name) < name_size - 1)
    {
        cout << __func__ << __LINE__ << endl;
        strcpy(this->_name, p._name);
    }
    else if( NULL == _name )
    {
        cout << __func__ << __LINE__ << endl;
        int len = strlen(p._name);
        _name = new char[len+1];
        strcpy(_name, p._name);
    }
    else
    {
        cout << __func__ << __LINE__ << endl;
        delete _name;
        int len = strlen(p._name);
        _name = new char[len+1];
        strcpy(_name, p._name);
        name_size = len+1;
    }
    _id = p._id;
    return *this;

}

Person::Person(const Person & p)
{
    this->_name = new char[strlen(p._name)+1];
    strcpy(this->_name, p._name);
    name_size = strlen(p._name) + 1;
    _id = p._id;
}

void Person::setName(char *sName)
{
    if(!sName)
        return;
    if(NULL !=_name && strlen(sName) < name_size - 1)
    {
        strcpy(_name, sName);
    }
    else if(NULL == _name)
    {
        int len = strlen(sName);
        _name = new char[len+1];
        strcpy(_name, sName);
        name_size = len+1;
    }
    else
    {
        delete _name;
        int len = strlen(sName);
        _name = new char[len+1];
        strcpy(_name, sName);
        name_size = len+1;
    }
}

void Person::showName()
{
    cout << _name << endl;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Person per1;
        per1.setName("Tony William");
        per1.showName();

        Person per2;
        per2.setName("Brad Pitt");
        per2 = per1;
        per2.showName();

        per2.setName("Tom");

        per2.showName();

        per1.showName();

    }

    return a.exec();
}
