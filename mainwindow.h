#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stable.h"
#include "mypushbutton.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void btn_left_receiver();
    void btn_right_receiver();
    void btn_both_receiver();
private:
    Ui::MainWindow *ui;
    QList<QList<MyPushButton*>> btnList;
    void initData();
    void initView();
    void draw(bool isMine);
};

#endif // MAINWINDOW_H
