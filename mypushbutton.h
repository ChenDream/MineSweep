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
signals:
    void leftClick();
    void rightClick();
};

#endif // MYPUSHBUTTON_H
