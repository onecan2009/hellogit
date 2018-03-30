/*
string 类的成员函数：
empty()，compare()，swap()，c_str()，copy()
*/

#define _1_

#ifdef _1_
//示例1
//string 类的一般用法
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    string s1("This "), s2("is a "), s3("string."); //字符串的初始化
    s1 += s2;   // 现在字符串也可以这样操作
    string s4 = s1 + s3;
    cout << s4 << endl;

    string s5("The length of that string is: ");
    cout << s5 << s4.length() << " characters." << endl;
L:
    cout << "Enter a sentence: " << endl;
    getline(cin, s2);
    if(s2.empty())
    {
        cout << "The string you input is empty, please input again." << endl;
        goto L;
    }
    cout << "Here is your sentence: \n" << s2 << endl;
    cout << "The length of it was: " << s2.length() << endl;
    //可以像数组一样使用索引到一个字符(但是注意string并不是一个数组)
    char ch = s2[3];
    cout << "ch= " <<ch << endl;
    return 0;
}
#endif

#ifdef _2_
//示例2
//比较字符串
#include <iostream>
#include <string>
using namespace std;
int main (int argc, char *argv[])
{
  string str1 ("green apple");
  string str2 ("red apple");

  if (str1.compare(str2) != 0)
    cout << str1 << " is not " << str2 << "\n";

  if (str1.compare("green apple") == 0)
    cout << "match str1\n";

  if (str2.compare("red apple") == 0)
    cout << "match str2\n";

  if (str1 != str2) //还可以用 ==, !=, >, < 比较
    cout << "str1 and str2 are different\n";

  return 0;
}
#endif


#ifdef _3_
//示例3
//字符串交换
#include <iostream>
#include <string>
using namespace std;
main (int argc, char *argv[])
{
  string buyer ("money");
  string seller ("goods");

  cout << "Before swap, buyer has " << buyer;
  cout << " and seller has " << seller << endl;

  seller.swap (buyer);
//  buyer.swap(seller);
  cout << "After swap, buyer has " << buyer;
  cout << " and seller has " << seller << endl;

  return 0;
}
#endif


#ifdef _4_
//示例4
//C和C++函数混合调用操作字符串,从string类获得C语言字符数组
#include <iostream>
#include <cstdio> //C语言里的头文件名前面加上c去掉.h
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
    //使用C语言里的stdin，setbuf，scanf和printf
    int age;
    char name[128];
    printf("please input name and age:\n");
    scanf("%s %d", name, &age);

    setbuf(stdin, NULL);//清除scanf留下来的\n,否则后面的getline会收到并返回

    printf("You are %s, %d\n", name, age); //C语言风格的输出

    cout << "Please input a sentence:" <<endl;  //C++ 风格的输出
    string str; //string 类型对象不是简单的字符数组，不能用printf直接打印
    char buffer[64];
    getline(cin, str);
    //返回一个以'\0'结尾的字符串数组地址，ptr是const char类型，不可修改
    const char *ptr = str.c_str();
    printf("<ptr = %s>\n", ptr);
    //string变量里的字符串考贝到字符数组里，注意，拷贝后不会自动添加 '\0'
    int length;
    length = str.copy(buffer, sizeof(buffer), 0);
    buffer[length]='\0';//需要手动在数组尾部加上'\0'
    printf("<buffer = %s>\n", buffer);
    return 0;
}
#endif

#ifdef _5_
//示例5
//字符串查找
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
    sting str ="Good look catches the eyes but Good Personality catches the heart.";
    int pos = 0;
    int count = 0;
    //查找str中catches的个数
    while( (pos = str.find("catches", pos)) != string::npos)
    {
        pos += sizeof("catches");
        count++;
    }
    cout << count << " catches found" << endl;
    return 0;
}
#endif/*
    string 类的成员函数：
    empty()，compare()，swap()，c_str()，copy()
    */

    #define _1_

    #ifdef _1_
    //示例1
    //string 类的一般用法
    #include <string>
    #include <iostream>
    using namespace std;
    int main(int argc, char *argv[])
    {
        string s1("This "), s2("is a "), s3("string."); //字符串的初始化
        s1 += s2;   // 现在字符串也可以这样操作
        string s4 = s1 + s3;
        cout << s4 << endl;

        string s5("The length of that string is: ");
        cout << s5 << s4.length() << " characters." << endl;
    L:
        cout << "Enter a sentence: " << endl;
        getline(cin, s2);
        if(s2.empty())
        {
            cout << "The string you input is empty, please input again." << endl;
            goto L;
        }
        cout << "Here is your sentence: \n" << s2 << endl;
        cout << "The length of it was: " << s2.length() << endl;
        //可以像数组一样使用索引到一个字符(但是注意string并不是一个数组)
        char ch = s2[3];
        cout << "ch= " <<ch << endl;
        return 0;
    }
    #endif

    #ifdef _2_
    //示例2
    //比较字符串
    #include <iostream>
    #include <string>
    using namespace std;
    int main (int argc, char *argv[])
    {
      string str1 ("green apple");
      string str2 ("red apple");

      if (str1.compare(str2) != 0)
        cout << str1 << " is not " << str2 << "\n";

      if (str1.compare("green apple") == 0)
        cout << "match str1\n";

      if (str2.compare("red apple") == 0)
        cout << "match str2\n";

      if (str1 != str2) //还可以用 ==, !=, >, < 比较
        cout << "str1 and str2 are different\n";

      return 0;
    }
    #endif


    #ifdef _3_
    //示例3
    //字符串交换
    #include <iostream>
    #include <string>
    using namespace std;
    main (int argc, char *argv[])
    {
      string buyer ("money");
      string seller ("goods");

      cout << "Before swap, buyer has " << buyer;
      cout << " and seller has " << seller << endl;

      seller.swap (buyer);
    //  buyer.swap(seller);
      cout << "After swap, buyer has " << buyer;
      cout << " and seller has " << seller << endl;

      return 0;
    }
    #endif


    #ifdef _4_
    //示例4
    //C和C++函数混合调用操作字符串,从string类获得C语言字符数组
    #include <iostream>
    #include <cstdio> //C语言里的头文件名前面加上c去掉.h
    #include <cstdlib>
    using namespace std;
    int main(int argc, char *argv[])
    {
        //使用C语言里的stdin，setbuf，scanf和printf
        int age;
        char name[128];
        printf("please input name and age:\n");
        scanf("%s %d", name, &age);

        setbuf(stdin, NULL);//清除scanf留下来的\n,否则后面的getline会收到并返回

        printf("You are %s, %d\n", name, age); //C语言风格的输出

        cout << "Please input a sentence:" <<endl;  //C++ 风格的输出
        string str; //string 类型对象不是简单的字符数组，不能用printf直接打印
        char buffer[64];
        getline(cin, str);
        //返回一个以'\0'结尾的字符串数组地址，ptr是const char类型，不可修改
        const char *ptr = str.c_str();
        printf("<ptr = %s>\n", ptr);
        //string变量里的字符串考贝到字符数组里，注意，拷贝后不会自动添加 '\0'
        int length;
        length = str.copy(buffer, sizeof(buffer), 0);
        buffer[length]='\0';//需要手动在数组尾部加上'\0'
        printf("<buffer = %s>\n", buffer);
        return 0;
    }
    #endif

    #ifdef _5_
    //示例5
    //字符串查找
    #include <iostream>
    #include <string>
    using namespace std;
    int main(int argc, char *argv[])
    {
        sting str ="Good look catches the eyes but Good Personality catches the heart.";
        int pos = 0;
        int count = 0;
        //查找str中catches的个数
        while( (pos = str.find("catches", pos)) != string::npos)
        {
            pos += sizeof("catches");
            count++;
        }
        cout << count << " catches found" << endl;
        return 0;
    }
    #endif
