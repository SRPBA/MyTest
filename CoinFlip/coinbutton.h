
#ifndef COINBUTTON_H
#define COINBUTTON_H


#include <QWidget>
#include <QPushButton>
#include <QTimer>


class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = nullptr);

    int stat() const;
    void setStat(int newStat);

    //setStat带动画的函数
    void setStatWithAnimation(int stat);

    //硬币翻转函数
    void flip();

protected:
    void paintEvent(QPaintEvent* ev);

private:
    //硬币状态:0表示银币，1表示金币
    int mStat;
    //记录当前动画帧数是第几帧
    int mFrame;
    //定时器
    QTimer mTimer;

signals:

};

#endif // COINBUTTON_H
