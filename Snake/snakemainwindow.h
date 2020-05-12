#ifndef SNAKEMAINWINDOW_H
#define SNAKEMAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "apple.h"
#include "gamewindow.h"
#include "snakebody.h"
#include "snakehead.h"
#include "ui_snakemainwindow.h"
#include "snaketitle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SnakeMainWindow; }
QT_END_NAMESPACE

class SnakeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SnakeMainWindow(QWidget *parent = nullptr);
    ~SnakeMainWindow();

protected slots:
    void StartGame();
private:
    QGraphicsScene *scene_;

    SnakeTitle *title_;

    SnakeHead *snake_head_;

    SnakeBody *snake_body_;
    SnakeBody *snake_body1_;
    SnakeBody *snake_body2_;
    SnakeBody *snake_body3_;
    Apple *apple_;

    Ui::SnakeMainWindow *ui;
    void setSnakeImage();
};
#endif // MAINWINDOW_H
