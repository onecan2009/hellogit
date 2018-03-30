#include <QCoreApplication>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        map<string, string> addr;
        addr["Tom"] = "Los Angeles";
        addr["Livy"] = "New York";
        addr["Tom"] = "Washington"; //overwrite exist association
        addr.insert(pair<string,string>("Blues", "Boston"));
        addr.insert(pair<string,string>("Livy", "Shanghai")); //fail to insert
        addr.insert(pair<string,string>("LongMan", "Lock Haven"));
        addr.insert(pair<string,string>("Zhou", "Chicago"));
        addr.insert(pair<string,string>("Bonse", "San Fransisco"));
        map<string, string>::iterator it;
        //it->first ----key
        //it->second -----value
        it = addr.find("LongMan");
        if(it != addr.end())
            cout << "find: " << it->first << it->second << endl;
        for(it = addr.begin(); it != addr.end(); it++)
            cout << it->first << " => " << it->second << endl;
        //use it for different object;
        map<string, string> addr2(addr);
        it = addr2.find("LongMan");
        if(it != addr2.end())
            cout << "find: " << it->first << it->second << endl;
    }
    
    return a.exec();
}
