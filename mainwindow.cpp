#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tools.h"
#include "global.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initView();
    this->initData();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initView(){
    ui->gridLayout->setSpacing(0);
    int len = 30;
    const QSize btnSize = QSize(len,len);
//    ui->gridLayout->setGeometry(QRect(10,10,len*9,len*9));
    ui->gridLayoutWidget->setGeometry(QRect(50,50,len*9,len*9));
    for(int i=0;i<9;i++){
        QList<QPushButton*> tem;
        for(int j=0;j<9;j++){
            QPushButton *btn;
            btn = new QPushButton(ui->gridLayoutWidget);
            QString name = QString::number(j)+"-"+QString::number(i);
            tem.append(btn);
            btn->setObjectName(name);
            btn->setFixedSize(btnSize);
            connect(btn,SIGNAL(clicked()),this,SLOT(btn_receiver()));
            ui->gridLayout->addWidget(btn,i,j);
        }
        btnList.append(tem);
    }
}

void MainWindow::initData(){
    Tools::GenerateMap(9,9,10);
//    Tools::PrintMap(Global::getInstance().map);
//    Tools::PrintMap(Global::getInstance().check_map);
}

void MainWindow::on_click_clicked()
{
    auto result = Tools::Click(0,0);
    auto lst = result.path;
    if(!lst.empty()){
        for(auto tem:lst){
            qDebug()<<tem.first<<tem.second;
        }
    }
}
void MainWindow::btn_receiver(){
    if(QPushButton* btn = qobject_cast<QPushButton *>(sender())){
        QStringList lst = btn->objectName().split("-");
        int x = lst.at(0).toInt();
        int y = lst.at(1).toInt();
        auto result =  Tools::Click(x,y);
    }

}
void MainWindow::draw(){
    int x = btnList.at(0).length();
    int y = btnList.length();
    for(int i =0;i<x;i++){
        for(int j=0;j<y;j++){

        }
    }
}
