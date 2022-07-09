#ifndef BOOK_H
#define BOOK_H
#include "iostream"
#include "map"
#include "set"
#include "string"
#include "functional"
using namespace std;

class book
{
    friend ostream& operator<<(ostream& cout, book& bk);
private:
    string name;
    string publish;
    string isbn;
    string author;
    string price;
    string num;
public:
    book();
    book(string Name,string Publish,string ISBN,string Author,string Price,string Num);
    string getName();
    void setName(string name);
    string getPublish();
    void setPublish(string publish);
    string getISBN();
    void setISBN(string ISBN);
    string getAuthor();
    void setAuthor(string Author);
    string getPrice();
    void setPrive(string price);
    string getNum();
    void setNum(string num);
    book& operator-(string n);
};

extern map<string,book> m;
extern set<string> sb;
#endif // BOOK_H
