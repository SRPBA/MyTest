
#ifndef MYSELECTSCENE_H
#define MYSELECTSCENE_H


#include <QMainWindow>
#include "mymainwindow.h"


class MySelectScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit MySelectScene(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

signals:
    void backBtnClicked();

};

#endif // MYSELECTSCENE_H
