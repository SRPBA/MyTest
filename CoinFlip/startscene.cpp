
#include "startscene.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QTimer>

StartScene::StartScene(QWidget *parent)
    : MyMainWindow{parent}
{
    this->setWindowTitle("开始场景");



    MyPushButton* btnStart = new MyPushButton(":/res/MenuSceneStartButton.png",":/res/MenuSceneStartButton.png",this);
    btnStart->resize(114,114);
    //按钮水平居中，垂直方向在3/4位置
    btnStart->move((this->width() - btnStart->width())/2,this->height()*3/4 - btnStart->height()/2);
    //按钮不规则样式    setStyleSheet("QPushButton{border:0px;}");
    btnStart->setStyleSheet("QPushButton{border:0px;}");
    //信号,返回窗口
    connect(&this->mSelectScene,&MySelectScene::backBtnClicked,[=](){
       //当第二个窗口返回按钮点击的时候
        this->show();
        this->mSelectScene.hide();
        this->move(this->mSelectScene.pos());
    });

    //信号，点击按钮
    connect(btnStart,&MyPushButton::clicked,[=](){
        //将按钮设置为不可用
        btnStart->setEnabled(false);
        //播放向下的动画
        btnStart->moveDonw();
        QTimer::singleShot(150,[=](){
            //往上走的动画会覆盖之前的动画
            //要等待之前动画播放完再调用
            btnStart->moveUp();
        });
        QTimer::singleShot(300,[=](){
            //启用按钮
            btnStart->setEnabled(true);

            //场景转换
            //隐藏当前窗口，同时显示第二个窗口
            this->hide();
            this->mSelectScene.show();
            //将窗口移动到当前窗口的位置
            this->mSelectScene.move(this->pos());

        });

    });

}

