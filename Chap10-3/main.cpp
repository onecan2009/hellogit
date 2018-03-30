#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        const char filename[] = "c:\\ccc.txt";
        ofstream o_file;
        ifstream i_file;
        string out_text;

        o_file.open(filename);
        for(int i=1; i <= 10; i++)
        {
            /*if(i==10)
                o_file<<"line_"<<"No_"<<i;
            else*/
                o_file<<"line_"<<"No_"<<i<<endl;
        }
        o_file.close();

        i_file.open(filename);

        if (i_file.is_open())
        {
            while (i_file.good())
            {
                i_file>>out_text;
                cout << out_text << endl;
            }
         }
         else
             cout<<"Open file"<<filename <<" error";
         i_file.close();
    }
    return a.exec();
}
