#include "mainwindow.h"
#include "book.h"
#include "FileController.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    fileImport("BookList.txt");//默认导入路径
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
