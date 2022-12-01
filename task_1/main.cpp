#include <iostream>
#include <cmath>
#include "string.h"

//функция для конвертации числа в строку
MyString to_string(int n)
{
    int m = n;
    int count = 0;
    while (m)
    {
        m /= 10;
        count++;
    }

    char s[count+1];
    for (int i = count-1; i >= 0; --i)
    {
        s[i] = char(48 + (n%10));
        n /= 10;
    }
    s[count] = '\0';

    return MyString(s);
}

//функция для конвертации строки в число
int from_string(MyString s)
{
    int length = s.get_len();
    char* st = s.get_str();
    int n = 0;
    for (int i = 0; i < length; ++i)
    {
        int sym = int(st[i]) - 48;
        n += sym*int(pow(10, (length-1-i)));
    }
    return n;
}

int main()
{
    /*
     с SSO не разобралась :(

     все вроде отрабатывает, но почему-то возникает SIGTRAP: trace/breakpoint trap
     и перекидывает в ассемблерный код, тоже разобраться не смогла :(
     */

    MyString s1 = "hello";
    MyString s2 = "ll";
    MyString s3 = s1+s2;
    std::cout << s3 << std::endl;

    MyString s4 = "awesome";
    s4.insert('f', 3);
    std::cout << s4 << std::endl;

    std::cout << "Start index of substring s2 in s1 is " << s1.find_str(s2.get_str()) << std::endl;

    int num1 = 209578274;
    MyString s5 = to_string(num1);
    std::cout << s5 << std::endl;

    MyString s6 = "180145";
    int num2 = from_string(s6);
    std::cout << num2 << std::endl;
}