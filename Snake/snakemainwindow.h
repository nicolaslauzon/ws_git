#ifndef SNAKEMAINWINDOW_H
#define SNAKEMAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include "gamewindow.h"
#include "ui_snakemainwindow.h"
#include "snakefactory.h"

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

    QGraphicsItem *title_;

    QGraphicsItem *snake_head_;

    QGraphicsItem *snake_body_;
    QGraphicsItem *snake_body1_;
    QGraphicsItem *snake_body2_;
    QGraphicsItem *snake_body3_;
    QGraphicsItem *apple_;

    Ui::SnakeMainWindow *ui;
    void setSnakeImage();
};
#endif // MAINWINDOW_H
