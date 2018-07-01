#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools.h"
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
}
