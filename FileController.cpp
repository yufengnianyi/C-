#include "FileController.h"
#include "iostream"
#include "fstream"
#include "book.h"
#include "vector"
#include <QFile>
#include <QTextStream>
#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QIODevice>

//import
void fileExport(string path)
{
    ofstream outfile(path, ios::out);
    if (outfile.fail()) {
        cout << "输入文件BookList.txt打开失败!\n";
        exit(1);
    }
    for (map<string, book>::iterator it = m.begin(); it != m.end(); it++)
    {
        outfile << it->second.getName() << "," << it->second.getPublish() << "," << it->second.getISBN() <<","<< it->second.getAuthor()<<","
            << it->second.getPrice()<<"," << it->second.getPrice() << endl;
    }
    outfile.close();
}

//split
void mySplit(const string& inStr, vector<string>& outStr,char *split)
{
    char *tempStr = new char[inStr.size()]; 
    inStr.copy(tempStr, inStr.size(), 0);
    *(tempStr + inStr.size()) = '\0';
    char *p2 = strtok(tempStr, split);
    while (p2 != NULL)
    {
        outStr.push_back(p2);
        p2 = strtok(NULL, split);
    }
}


//import
void fileImport(string fpath)
{
    ifstream infile;
        infile.open(fpath);
    if (infile.fail()) {
        cout << "error export!\n";
        exit(1);
    }
    m.clear();
    string s;
    while(getline(infile,s))
    {
        vector<string> outStr;
        mySplit(s, outStr, ",");
        book *tmp = new book(outStr[0],outStr[1],outStr[2],outStr[3],outStr[4],outStr[5]);
        m.insert(make_pair(outStr[2],(*tmp)));
    }
    infile.close();
}
