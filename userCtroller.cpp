#include "userCtroller.h"
#include "QtSql/QSqlDatabase"
#include "QMessageBox"
#include "QSqlQuery"
#include "QDebug"
#include "ui_mainwindow2.h"

bool Login(string name,string pwd)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost_3306");
    db.setPort(3306);
    db.setDatabaseName("booklist");
    db.setUserName("root");
    db.setPassword("123456");
    QSqlQuery query;
    QVariant temp = query.value(0);
    qDebug() << temp.toString();

    return false;
}

