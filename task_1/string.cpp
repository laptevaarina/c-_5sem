#include <iostream>
#include "string.h"

MyString::MyString()
{
    len = 1;
    str = new char [1];
    str[0] = '\0';
}

MyString::MyString(char* s)
{
    len = size_of(s);
    str = new char [len+1];
    copy(s, str);
}

int MyString::size_of(char *s)
{
    int count = 0;
    char* tmp = s;
    while(*tmp)
    {
        count++;
        tmp++;
    }
    return count;
}

void MyString::copy(char *from, char *to)
{
    char* tmp_from = from;
    char* tmp_to = to;
    while(*tmp_from)
    {
        *tmp_to = *tmp_from;
        tmp_to++;
        tmp_from++;
    }
    *tmp_to = '\0';
}

std::ostream & operator<<(std::ostream & os, MyString &s)
{
    char *st = s.get_str();
    os << st;
    return os;
}

MyString::~MyString()
{
    len = 0;
    delete[] str;
}

MyString operator+(MyString &s1, MyString &s2)
{
    char* st1 = s1.get_str();
    char* tmp1 = st1;

    char* st2 = s2.get_str();
    char* tmp2 = st2;

    char* st_new = new char [s1.get_len()+s2.get_len()+1];
    char* tmp_new = st_new;

    while(*tmp1)
    {
        *tmp_new = *tmp1;
        tmp1++;
        tmp_new++;
    }

    while(*tmp2)
    {
        *tmp_new = *tmp2;
        tmp2++;
        tmp_new++;
    }

    *tmp_new = '\0';

    return MyString(st_new);
}


int MyString::find_str_idx(char *find_in, char *find_it, int n)
{
    int len_in = size_of(find_in);
    int len_it = size_of(find_it);

    for (int i = 0; i <= len_in - len_it; i++)
    {
        int j;
        for (j = 0; find_in[i + j] == find_it[j]; j++);

        if (j - len_it == 1 && i == len_in - len_it && !(n - 1))
            return i;
        if (j == len_it) {
            if (n - 1) {
                n--;
            } else {
                return i;
            }
        }
    }
    return -1;
}

int MyString::find_str(char *find_it)
{
    int n = 0;
    for (int i = 1; n != -1; i++)
    {
        n = find_str_idx(str, find_it, i);

        if (n >= 0)
            return n;
    }
    return -1;
}

void MyString::insert(char sym, int pos)
{
    if (pos < 0 || pos >= len)
        return;

    for (int i = len+1; i >= pos; --i)
    {
        str[i] = str[i-1];
    }
    str[pos] = sym;
    len++;
}