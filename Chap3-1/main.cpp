#include <QCoreApplication>
#include <iostream>
using namespace std;
//Student: add deposit and withdraw function.

class Savings
{protected:
    int balance = 1000;
    bool check(char* usr, char* psw);
public:
    Savings(){}
public:
    int getBalance(char* usr, char* psw);
    void setBalance(int i);};

int Savings::getBalance(char* usr, char* psw)
{
    if(this->check(usr,psw))
    {        cout<<"balance is:"<<balance<<"\n";
        return balance;    }
    else
    {        cout<<"error\n";    }
    return 0;
}

void Savings::setBalance(int i)
{    balance = i;
}

bool Savings::check(char *usr, char *psw)
{
    if((usr == "zmb082")&&(psw=="123123"))
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Savings s;

    s.getBalance("zmb082","123123");

    s.setBalance(1920);
    s.getBalance("zmb082","123123");
    return a.exec();
}
