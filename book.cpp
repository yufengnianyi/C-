#include "book.h"

//typedef pair<string, book> PII;
//struct cmp {
//    bool operator()(PII& x, PII& y) {
//        x.second.getPrice() < y.second.getPrice();
//    }
//};
map<string, book> m;
set<string> sb;

book::book(){}
book::book(string Name,string Publish,string ISBN,string Author,string Price,string Num)
{
    name = Name;
    publish = Publish;
    isbn = ISBN;
    author = Author;
    price = Price;
    num = Num;
}

string book::getName()
{
        return name;
}

void book::setName(string name)
{
        this->name = name;
}

string book::getPublish()
{
        return publish;
}

void book::setPublish(string publish)
{
        this->publish = publish;
}

string book::getISBN()
{
        return isbn;
}

void book::setISBN(string ISBN)
{
        this->isbn = ISBN;
}

string book::getAuthor()
{
        return author;
}

void book::setAuthor(string Author)
{
        this->author = Author;
}

string book::getPrice()
{
        return price;
}

void book::setPrive(string price)
{
        this->price = price;
}

string book::getNum()
{
        return num;
}

void book::setNum(string num)
{
        this->num = num;
}

ostream& operator<<(ostream& cout, book& bk)
{
    cout << bk.name << "," << bk.price << "," << bk.isbn<<","<< bk.author<<","
        << bk.price <<"," << bk.num << endl;
    return cout;
}

book& book::operator-(string n)
{
    int a = atoi(n.c_str());
    int b = atoi(this->getNum().c_str());
    b = b - a;
    string tmp = std::to_string(b);
    this->setNum(tmp);
    return *this;
}
