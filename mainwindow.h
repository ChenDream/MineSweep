#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stable.h"
#include <QPushButton>
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

    void on_click_clicked();
    void btn_receiver();
private:
    Ui::MainWindow *ui;
    QList<QList<QPushButton*>> btnList;
    void initData();
    void initView();
};

#endif // MAINWINDOW_H
