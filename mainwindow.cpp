#include "mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow.h"
#include "userCtroller.h"
#include "QFileDialog"
#include "QPushButton"
#include "QFile"
#include "string"
#include "cstring"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置窗口大小
    int width = 450;
    int height = 350;
    this->setFixedSize(width,height);

    //实例化page2
    this->page2 = new MainWindow2;
    connect(ui->Enter_btn,&QPushButton::clicked,[=](){
        //切换窗口
        //1.隐藏当前的主窗口
        this->hide();
        //2.显示page2
        this->page2->show();
    });
    connect(this->page2,&MainWindow2::back,[=](){
        this->page2->hide();
        this->show();
    });

    QFont ft;
    ft.setPointSize(20);
    ui->title_label->setFont(ft);

    QString username;
    QByteArray arr= username.toUtf8();
    std::string cstr= arr.data();
    QString password;
    QByteArray arr2= username.toUtf8();
    string cstr2= arr.data();


}

MainWindow::~MainWindow()
{
    delete ui;
}

