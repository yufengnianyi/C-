#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow2.h"
#include "ui_mainwindow2.h"//页面二

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
    //保存页面二实例化对象的地址
    MainWindow2 *page2 = NULL;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
