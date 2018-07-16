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
        QList<MyPushButton*> tem;
        for(int j=0;j<9;j++){
            MyPushButton *btn;
            btn = new MyPushButton(ui->gridLayoutWidget);
            QString name = QString::number(j)+"-"+QString::number(i);
            tem.append(btn);
            btn->setObjectName(name);
            btn->setFixedSize(btnSize);
            connect(btn,SIGNAL(leftClick()),this,SLOT(btn_left_receiver()));
            connect(btn,SIGNAL(rightClick()),this,SLOT(btn_right_receiver()));
            ui->gridLayout->addWidget(btn,i,j);
        }
        btnList.append(tem);
    }
}

void MainWindow::initData(){
    Tools::GenerateMap(9,9,10);
}


void MainWindow::btn_left_receiver(){
    if(MyPushButton* btn = qobject_cast<MyPushButton *>(sender())){
        QStringList lst = btn->objectName().split("-");
        int x = lst.at(0).toInt();
        int y = lst.at(1).toInt();
        auto isMine =  Tools::Click(x,y);
        this->draw(isMine);
    }
}
void MainWindow::btn_right_receiver(){

    QIcon flag;
    QIcon question;
    flag.addFile(QStringLiteral(":/resources/flag.png"), QSize(), QIcon::Normal, QIcon::Off);
    question.addFile(QStringLiteral(":/resources/question.png"), QSize(), QIcon::Normal, QIcon::Off);

    if(MyPushButton* btn = qobject_cast<MyPushButton *>(sender())){

        if(btn->icon().isNull()){

            btn->setIcon(flag);

        }/*else if(btn->icon()==flag){

            btn->setIcon(question);
        }else if(btn->icon()==question){

            btn->setIcon(QIcon());
        }*/
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
