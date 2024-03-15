
#ifndef STARTSCENE_H
#define STARTSCENE_H


#include <QMainWindow>
#include "mymainwindow.h"
#include "myselectscene.h"


class StartScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);

private:
    MySelectScene mSelectScene;

signals:

};

#endif // STARTSCENE_H
