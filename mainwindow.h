#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_result_clicked();

    void on_click_clicked();

private:
    Ui::MainWindow *ui;
    void initData();
};

#endif // MAINWINDOW_H
