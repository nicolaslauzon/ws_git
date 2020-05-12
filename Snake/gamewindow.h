#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "apple.h"
#include "snakebody.h"
#include "snakehead.h"

#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(int w = 800, int h = 600, int difficulty = 0, QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

    QGraphicsScene *scene_;
    std::list<SnakeBody*> snake_tail_;
    SnakeHead *snake_head_;
    Apple *fruit_;

    void Setup();
    void FruitPlacement();
};

#endif // GAMEWINDOW_H
