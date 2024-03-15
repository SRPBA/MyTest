
#ifndef PLAYSCENE_H
#define PLAYSCENE_H


#include <QMainWindow>
#include "mymainwindow.h"
#include "coinbutton.h"


class PlayScene : public MyMainWindow
{
    Q_OBJECT
public:
    PlayScene(int level, QWidget *parent = nullptr);
    //翻动row行col列的硬币
    void flip(int row, int col);
    //判断胜利
    void judgeWin();

protected:
    void paintEvent(QPaintEvent* event);

private:
    //硬币按钮数组
    CoinButton* mCoins[4][4];
    //胜利状态
    bool mHasWin;

signals:
    //点击返回按钮发出的信号
    void backBtnClicked();


};

#endif // PLAYSCENE_H
