#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "BookController.h"
#include "cstring"
#include "vector"
#include "set"
#include "stdlib.h"
#include <QMessageBox>
#include "FileController.h"


MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
//    //设置窗口大小
//    int width = 1000;
//    int height = 800;
//    this->setFixedSize(width,height);

    connect(ui->back_btn,&QPushButton::clicked,[=](){
        //发送一个信号
        emit this->back();
    });

    //设置初始默认页面
    ui->stackedWidget->setCurrentIndex(0);
    //页面跳转
    connect(ui->page1,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->page2,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->page3,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->page4,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(3);
    });


    //查询
    ui->quert_Edit->setText("请输入书名");
    //记录查找过的
    connect(ui->query_btn,&QPushButton::clicked,[&](){
        QString str = ui->quert_Edit->text();
        QByteArray arr = str.toUtf8();
        string cstr = arr.data();
        book bk = findByName(cstr);
        //判断是否找到
        if(bk.getNum()=="")
        {
            QMessageBox::critical(this,"error","没有找到对应书目");
            return 0;
        }
        if(setFind(bk.getISBN()))
        {
            QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<< QString::fromStdString(bk.getName()));
            ui->query_tw->addTopLevelItem(item1);
            QTreeWidgetItem * l1 = new QTreeWidgetItem(QStringList()<<"作者："<<QString::fromUtf8(bk.getName().c_str(), bk.getName().length()));
            QTreeWidgetItem * l2 = new QTreeWidgetItem(QStringList()<<"出版社："<<QString::fromStdString(bk.getPublish()));
            QTreeWidgetItem * l3 = new QTreeWidgetItem(QStringList()<<"ISBN编码："<<QString::fromStdString(bk.getISBN()));
            QTreeWidgetItem * l4 = new QTreeWidgetItem(QStringList()<<"数量："<<QString::fromStdString(bk.getNum()));
            QTreeWidgetItem * l5 = new QTreeWidgetItem(QStringList()<<"价格"<<QString::fromStdString(bk.getPrice()));
            item1->addChild(l1);
            item1->addChild(l2);
            item1->addChild(l3);
            item1->addChild(l4);
            item1->addChild(l5);
        }else{
            QMessageBox::information(this,"information","已经查找过了");
            return 0;
        }
    });

    ui->quert_Edit_2->setText("请输入完整的ISBN编码！");
    connect(ui->query_btn_2,&QPushButton::clicked,[=](){
        QString str2 = ui->quert_Edit_2->text();
        QByteArray arr2 = str2.toUtf8();
        string cstr = arr2.data();
        book bk = findByISBN(cstr);
        QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<< QString::fromStdString(bk.getName()));
        if(bk.getNum()=="")
        {
            QMessageBox::critical(this,"error","没有找到该标题！");
            return 0;
        }
        if(setFind(bk.getISBN()))
        {
            ui->query_tw->addTopLevelItem(item1);
            QTreeWidgetItem * l1 = new QTreeWidgetItem(QStringList()<<"作者："<<QString::fromStdString(bk.getAuthor()));
            QTreeWidgetItem * l2 = new QTreeWidgetItem(QStringList()<<"出版社："<<QString::fromStdString(bk.getPublish()));
            QTreeWidgetItem * l3 = new QTreeWidgetItem(QStringList()<<"ISBN编码："<<QString::fromStdString(bk.getISBN()));
            QTreeWidgetItem * l4 = new QTreeWidgetItem(QStringList()<<"数量："<<QString::fromStdString(bk.getNum()));
            QTreeWidgetItem * l5 = new QTreeWidgetItem(QStringList()<<"价格"<<QString::fromStdString(bk.getPrice()));
            item1->addChild(l1);
            item1->addChild(l2);
            item1->addChild(l3);
            item1->addChild(l4);
            item1->addChild(l5);
        }else{
            QMessageBox::information(this,"information","已经查找过了");
            return 0;
        }
    });

    //添加
    connect(ui->add_btn,&QPushButton::clicked,[=](){
        QString s1 = ui->edit_1->text();
        QString s2 = ui->edit_2->text();
        QString s3 = ui->edit_3->text();
        QString s4 = ui->edit_4->text();
        QString s5 = ui->edit_5->text();
        QString s6 = ui->edit_6->text();
        QByteArray a1 = s1.toUtf8();
        string cs1 = a1.data();
        QByteArray a2 = s2.toUtf8();
        string cs2 = a2.data();
        QByteArray a3 = s3.toUtf8();
        string cs3 = a3.data();
        QByteArray a4 = s4.toUtf8();
        string cs4 = a4.data();
        QByteArray a5 = s5.toUtf8();
        string cs5 = a5.data();
        QByteArray a6 = s6.toUtf8();
        string cs6 = a6.data();
        if(m.count(cs4) == 1)
        {
            QMessageBox::critical(this,"error","该ISBN编码已经存在！！");
            return 0;
        }
        addBook(cs1,cs2,cs3,cs4,cs5,cs6);
        QMessageBox::information(this,"提示","添加成功");
        ui->edit_1->clear();
        ui->edit_2->clear();
        ui->edit_3->clear();
        ui->edit_4->clear();
        ui->edit_5->clear();
        ui->edit_6->clear();
    });

    //修改
    connect(ui->change_btn,&QPushButton::clicked,[=](){
        QString s1 = ui->edit_1->text();
        QString s2 = ui->edit_2->text();
        QString s3 = ui->edit_3->text();
        QString s4 = ui->edit_4->text();
        QString s5 = ui->edit_5->text();
        QString s6 = ui->edit_6->text();
        QByteArray a1 = s1.toUtf8();
        string cs1 = a1.data();
        QByteArray a2 = s2.toUtf8();
        string cs2 = a2.data();
        QByteArray a3 = s3.toUtf8();
        string cs3 = a3.data();
        QByteArray a4 = s4.toUtf8();
        string cs4 = a4.data();
        QByteArray a5 = s5.toUtf8();
        string cs5 = a5.data();
        QByteArray a6 = s6.toUtf8();
        string cs6 = a6.data();
        if(m.count(cs4) == 0)
        {
            QMessageBox::critical(this,"error","该ISBN编码不存在！！");
            return 0;
        }
        changeBook(cs1,cs2,cs3,cs4,cs5,cs6);
        QMessageBox::information(this,"提示","修改成功");
        ui->edit_1->clear();
        ui->edit_2->clear();
        ui->edit_3->clear();
        ui->edit_4->clear();
        ui->edit_5->clear();
        ui->edit_6->clear();
    });

    //统计
    connect(ui->statistical_btn,&QPushButton::clicked,[=](){
        ui->statistical_widget->clear();
        for(map<string,book>::iterator ib = m.begin();ib != m.end();ib++)
        {
            QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<< QString::fromStdString((*ib).second.getName()));
            ui->statistical_widget->addTopLevelItem(item1);
            QTreeWidgetItem * l1 = new QTreeWidgetItem(QStringList()<<"ISBN编码："<<QString::fromStdString((*ib).second.getISBN()));
            QTreeWidgetItem * l2 = new QTreeWidgetItem(QStringList()<<"数量："<<QString::fromStdString((*ib).second.getNum()));
            QTreeWidgetItem * l3 = new QTreeWidgetItem(QStringList()<<"价格"<<QString::fromStdString((*ib).second.getPrice()));
            item1->addChild(l1);
            item1->addChild(l2);
            item1->addChild(l3);
        }
    });

    //删除
    ui->delete_edit->setText("请入ISBN编码：");
    connect(ui->delete_btn,&QPushButton::clicked,[=](){
        QString qs = ui->delete_edit->text();
        QByteArray arr = qs.toUtf8();
        string cs = arr.data();
        if(!m.count(cs))
        {
            QMessageBox::critical(this,"error","该ISBN编码不存在！！");
            return 0;
        }
        m.erase(cs);
        QMessageBox::information(this,"提示","删除成功");
    });

    //出售
    connect(ui->sell_btn,&QPushButton::clicked,[=](){
        QString qs1 = ui->sell_isbn_btn->text();
        QByteArray ar1 = qs1.toUtf8();
        string cs1 = ar1.data();

        QString qs2 = ui->num_edit->text();
        QByteArray arr2 = qs2.toUtf8();
        string cs2 = arr2.data();

        book& tmp = findByISBN(cs1);
        if((atoi(tmp.getNum().c_str())-atoi(cs2.c_str()))<0)
        {
            QMessageBox::critical(this,"error","库存不足");
            return 0;
        }
        tmp-cs2;
        QMessageBox::information(this,"提示","成功售出"+qs2+"本");
    });

    //导入 导出
    connect(ui->import_btn,&QPushButton::clicked,[=](){
        QString fpath = ui->import_edit->text();
        QByteArray arr= fpath.toUtf8();
        string cstr= arr.data();
        fileImport(cstr+".txt");
        QMessageBox::information(this,"提示","成功导入"+fpath);
        ui->import_edit->clear();
    });

    connect(ui->export_btn,&QPushButton::clicked,[=](){
        QString fpath = ui->export_edit->text();
        QByteArray arr= fpath.toUtf8();
        string cstr= arr.data();
        fileExport(cstr+".txt");
        QMessageBox::information(this,"提示","成功导出"+fpath);
        ui->export_edit->clear();
    });

}

MainWindow2::~MainWindow2()
{
    delete ui;
}
