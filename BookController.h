#ifndef BOOKCONTROLLER_H
#define BOOKCONTROLLER_H
#include "iostream"
#include "book.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "set"
#include "string"

book& findByName(string _name);
book& findByISBN(string _isbn);
bool setFind(string isnb);
void addBook(string s1,string s2,string s3,string s4,string s5,string s6);
void changeBook(string s1,string s2,string s3,string s4,string s5,string s6);
#endif // BOOKCONTROLLER_H
