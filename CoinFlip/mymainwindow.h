
#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QPainter>



QT_BEGIN_NAMESPACE
namespace Ui { class MyMainWindow; }
QT_END_NAMESPACE

class MyMainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MyMainWindow(QWidget *parent = nullptr);
    ~MyMainWindow();

protected:
    //绘制背景图片
    void paintEvent(QPaintEvent* event);

private:
    Ui::MyMainWindow *ui;
};

#endif // MYMAINWINDOW_H
