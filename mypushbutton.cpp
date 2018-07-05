#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget* parent):
    QPushButton(parent)
{

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        emit leftClick();
    }else if(e->button()==Qt::RightButton){
        emit rightClick();
    }
}
