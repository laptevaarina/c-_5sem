class MyString
{
private:
    char* str;
    int len;

public:
    MyString();
    MyString(char* s);
    ~MyString();

    int get_len() { return len; } //получение длины строки
    char* get_str() { return str; }
    char & operator[](int i) { return str[i]; }
    void insert(char sym, int pos); //добавление элемента
    int find_str(char* find_it); //поиск подстроки в строке

    static int size_of(char* s);
    static void copy(char* from, char* to);
    static int find_str_idx(char* find_in, char* find_it, int n);

    friend std::ostream& operator<<(std::ostream &os, MyString &s);
    friend MyString operator+(MyString &s1, MyString &s2); //конкатенация
};