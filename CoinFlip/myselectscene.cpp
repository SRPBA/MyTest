
#include "myselectscene.h"
#include <QPushButton>
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include "playscene.h"

MySelectScene::MySelectScene(QWidget *parent)
    : MyMainWindow{parent}
{
    //返回按钮
    MyPushButton* btnBack = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png",this);
    btnBack->resize(72,32);
    connect(btnBack,&QPushButton::clicked,this,&MySelectScene::backBtnClicked);

    btnBack->move(this->width() - btnBack->width(), this->height() - btnBack->height());

    //关卡按钮20个
    const int colWidth = 70;
    const int rowHeight = 70;
    //x y 偏移
    const int xOffset = 25;
    const int yOffset = 130;
    for(int i = 0; i < 20; i++){
        MyPushButton* btn = new MyPushButton(":/res/LevelIcon.png",":/res/LevelIcon.png",this);
        btn->setText(QString::number(i+1));
        //排列
        //行 i/4
        //列 i%4
        int row = i/4;
        int col = i%4;

        //x 坐标 = 列数 * 列宽 + x偏移
        //y 坐标 = 行数 * 行高 + y偏移
        int x = col * colWidth + xOffset;
        int y = row * rowHeight + yOffset;
        btn->resize(57,57);
        btn->move(x,y);

        connect(btn,&MyPushButton::clicked,[=](){
            //点击关卡按钮后，打开一个新的场景
            PlayScene* playScene = new PlayScene(i+1);
            //设置playScene关闭的时候自动释放
            playScene->setAttribute(Qt::WA_DeleteOnClose);
            playScene->move(this->pos());
            playScene->show();
            this->hide();

            connect(playScene,&PlayScene::backBtnClicked,[=](){

                this->move(playScene->pos());
                this->show();
                playScene->close();
            });
        });

    }



}

void MySelectScene::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPainter painter(this);
    painter.translate(0,this->menuBar()->height());
    QPixmap pix(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())/2,0,pix);


}

