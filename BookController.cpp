#include "BookController.h"
#include "algorithm"
#include <QMessageBox>
#include "mainwindow2.h"


//匹配规则
class map_value_finder
{
public:
    map_value_finder(const std::string &cmp_string):m_s_cmp_string(cmp_string){}
//    bool operator()(std::map<string,book>::value_type &pair)
//    {
//        return pair.second.getName() == m_s_cmp_string;
//    }
    bool operator ()(map<string,book>::value_type& pair)
    {
        int loc;
        loc=pair.second.getName().find(m_s_cmp_string);
        if (loc != pair.second.getName().npos)
            return true;
        return false;
    }
private:
    const std::string &m_s_cmp_string;
};

//名称的模糊查找
book& findByName(string _name)
{
    if(m.empty())
    {
        cout << "booklist is empty" << endl;
        exit(1);
    }
    map<string,book>::iterator it = m.end();
    //判断_name是否包含在m中
    it = std::find_if(m.begin(),m.end(),map_value_finder(_name));
    if(it == m.end())
    {
        book *tmp = new book;
        return *tmp;
    }
    return (it->second);
}

class book_ISBN_finder
{
public:
    book_ISBN_finder(const std::string &cmp_string):m_s_cmp_string(cmp_string){}
    bool operator()(std::map<string,book>::value_type &pair)
    {
        return pair.second.getISBN() == m_s_cmp_string;
    }
private:
    const std::string &m_s_cmp_string;
};

book& findByISBN(string _isbn)
{
    if(m.empty())
    {
        cout << "booklist is empty" << endl;
        exit(1);
    }
    map<string,book>::iterator it = m.end();
    it = std::find_if(m.begin(),m.end(),book_ISBN_finder(_isbn));
    if(it == m.end())
    {
        book *tmp = new book;
        return *tmp;
    }
    return (it->second);
}

//判断是否已经查找过
bool setFind(string isnb)
{
    if(sb.count(isnb) == 0)
    {
        sb.insert(isnb);
        return true;
    }else{
        return false;
    }
}

//添加书本
void addBook(string s1,string s2,string s3,string s4,string s5,string s6)
{
    //string Name,string Publish,string ISBN,string Author,string Price,string Num)
    book tmp(s1,s3,s4,s2,s5,s6);
    m.insert(make_pair(s4,tmp));
}

//修改书本
void changeBook(string s1,string s2,string s3,string s4,string s5,string s6)
{
    map<string,book>::iterator it = m.lower_bound(s4);
    (*it).second.setName(s1);
    (*it).second.setAuthor(s2);
    (*it).second.setPublish(s3);
    (*it).second.setPrive(s5);
    (*it).second.setNum(s6);
}



