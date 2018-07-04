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
    const QSize btnSize = QSize(50,50);
    for(int i=0;i<9;i++){
        QList<QPushButton*> tem;
        for(int j=0;j<9;j++){
            QPushButton *btn;
            btn = new QPushButton(ui->gridLayoutWidget);
            QString name = QString::number(i)+"-"+QString::number(j);
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
        qDebug()<<btn->objectName();
    }
}
