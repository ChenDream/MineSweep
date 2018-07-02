#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools.h"
#include "global.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initData();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initData(){
    Tools::GenerateMap(9,9,10);
    Tools::PrintMap(Global::getInstance().map);
    Tools::PrintMap(Global::getInstance().check_map);

}
