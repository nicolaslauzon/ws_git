#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "snakefactory.h"
#include "snake.h"

#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(int w = 800, int h = 600, float difficulty = 0, QWidget *parent = nullptr);
    ~GameWindow();

protected:
    void keyPressEvent(QKeyEvent *) override;
    void closeEvent(QCloseEvent *) override;
protected slots:
    void timeoutEvent();
private:
    Ui::GameWindow *ui;

    float speed_;
    QGraphicsScene *scene_;
    QGraphicsItem *fruit_;
    Snake *snake_;
    QTimer *timer_;
    int last_key_press_;
    void Setup();
    void FruitPlacement();
    void ResetFruit();
};

#endif // GAMEWINDOW_H
