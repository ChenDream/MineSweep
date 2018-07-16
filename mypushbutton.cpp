#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget* parent):
    QPushButton(parent)
{

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        if(holding>=2){
            holding =0;
            emit bothClick();
        }else if((--holding) ==0){
            emit leftClick();
        }
    }else if(e->button()==Qt::RightButton){
        if(holding>=2){
            holding =0;
            emit bothClick();
        }else if((--holding) ==0){
            emit rightClick();
        }
    }
}
void MyPushButton::mousePressEvent(QMouseEvent *e){
    if(e->button()==Qt::LeftButton){
        holding++;
    }else if(e->button()==Qt::RightButton){
        holding++;
    }
}
