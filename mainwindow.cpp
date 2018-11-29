#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minealgorithm.h"
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
    ui->gridLayoutWidget->setGeometry(QRect(50,50,len*9,len*9));
    for(int i=0;i<9;i++){
        QList<MyPushButton*> tem;
        for(int j=0;j<9;j++){
            MyPushButton *btn;
            btn = new MyPushButton(ui->gridLayoutWidget);
            //object name format is row-column-flag
            QString name = QString::number(j)+"-"+QString::number(i)+"-0";
            tem.append(btn);
            btn->setObjectName(name);
            btn->setFixedSize(btnSize);
            connect(btn,SIGNAL(leftClick()),this,SLOT(btn_left_receiver()));
            connect(btn,SIGNAL(rightClick()),this,SLOT(btn_right_receiver()));
            connect(btn,SIGNAL(bothClick()),this,SLOT(btn_both_receiver()));
            ui->gridLayout->addWidget(btn,i,j);
        }
        btnList.append(tem);
    }
}

void MainWindow::initData(){
    MineAlgorithm::GenerateMap(9,9,10);
}

void MainWindow::btn_both_receiver(){
    if(MyPushButton* btn = qobject_cast<MyPushButton *>(sender())){
        qDebug()<<"both";
    }
}

void MainWindow::btn_left_receiver(){
    if(MyPushButton* btn = qobject_cast<MyPushButton *>(sender())){
        QStringList lst = btn->objectName().split("-");
        if(lst.at(2)!="0"){
            return;
        }
        int x = lst.at(0).toInt();
        int y = lst.at(1).toInt();
        auto isMine =  MineAlgorithm::Click(x,y);
        this->draw(isMine);
    }
}
void MainWindow::btn_right_receiver(){

    QIcon flag;
    QIcon question;
    flag.addFile(QStringLiteral(":/resources/flag.png"), QSize(), QIcon::Normal, QIcon::Off);
    question.addFile(QStringLiteral(":/resources/question.png"), QSize(), QIcon::Normal, QIcon::Off);

    if(MyPushButton* btn = qobject_cast<MyPushButton *>(sender())){

        QStringList lst = btn->objectName().split("-");
        QString name = lst[0]+"-"+lst[1]+"-";
        if(lst[2]=="0"||btn->icon().isNull()){
            btn->setIcon(flag);
            name.append("1");
        }else if(lst[2]=="1"){
            btn->setIcon(question);
            name.append("2");
        }else if(lst[2]=="2"){
            btn->setIcon(QIcon());
            name.append("0");
        }
        btn->setObjectName(name);
    }
}

void MainWindow::draw(bool isMine){
     //type = -1 game over, find all mines
    int x = btnList.at(0).length();
    int y = btnList.length();
    for(int i =0;i<y;i++){
        for(int j=0;j<x;j++){
            if(isMine && Global::getInstance().check_map[j][i] == -1){
                btnList[j][i]->setText("-1");
                btnList[j][i]->setEnabled(false);
            }else if(Global::getInstance().check_map[j][i]==1){
                btnList[j][i]->setText(QString::number(Global::getInstance().map[j][i]));
                btnList[j][i]->setEnabled(false);
            }
        }
    }
}
