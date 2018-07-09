#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget* parent =0);
private slots:
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *e);
signals:
    void leftClick();
    void rightClick();
    void bothClick();
private:
    int holding = 0;
};

#endif // MYPUSHBUTTON_H
