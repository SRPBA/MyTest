
#include "mypushbutton.h"
#include <QPainter>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg, QString pressedImg, QWidget *parent)
    : QPushButton{parent}
    ,mNormalImg(normalImg)
    ,mPressedImg(pressedImg)
{
    mStat = Normal;
}

void MyPushButton::moveDonw()
{
    //1 位置大小属性发生变化
    //2 给定开始的位置大小属性
    //3 给定结束的位置大小属性
    //4 给定速度，给定动画时长

    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(200);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::moveUp()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(200);
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void MyPushButton::paintEvent(QPaintEvent *ev)
{
    //绘制按钮的图片
    QPainter painter(this);
    QPixmap pix;
    if(mStat == Normal)
        pix.load(mNormalImg);
    if(mStat == Pressed)
        pix.load(mPressedImg);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //绘制按钮的文字
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignHCenter|Qt::AlignVCenter,this->text());
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    this->mStat = Pressed;
    update();
    //保证信号和槽功能，调用父类事件处理函数
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->mStat = Normal;
    update();
    QPushButton::mouseReleaseEvent(e);
}

