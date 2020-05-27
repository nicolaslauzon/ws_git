#include "gamewindow.h"
#include "ui_gamewindow.h"

#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

GameWindow::GameWindow(int w, int h, float difficulty, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    speed_ = difficulty;
    timer_ = nullptr;
    ui->snake_game_->setFixedSize(w, h);
    Setup();
    FruitPlacement();
    ui->snake_game_->setScene(scene_);
}

GameWindow::~GameWindow()
{
    if (timer_!=nullptr) {
        timer_->stop();
        timer_->deleteLater();
        timer_=nullptr;
    }
    delete ui;
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() != last_key_press_) {
        last_key_press_ = event->key();
    }
    if (!timer_) {
        timer_ = new QTimer(this);
        connect(timer_, SIGNAL(timeout()), this, SLOT(timeoutEvent()));
        timer_->setSingleShot(true);
        float timeout=speed_ * 1000;
        timer_->start(timeout);
    }
}

void GameWindow::closeEvent(QCloseEvent *)
{
    if (timer_){
        timer_->stop();
        timer_->deleteLater();
        timer_=nullptr;
    }
}

void GameWindow::timeoutEvent()
{
    if(last_key_press_ == Qt::Key_W && snake_->TopDirection() != South) {        
        snake_->SetDirection(North);
    }
    if(last_key_press_ == Qt::Key_A && snake_->TopDirection() != East) {        
        snake_->SetDirection(West);
    }
    if(last_key_press_ == Qt::Key_S && snake_->TopDirection() != North) {       
        snake_->SetDirection(South);
    }
    if(last_key_press_ == Qt::Key_D && snake_->TopDirection() != West) {        
        snake_->SetDirection(East);
    }
    snake_->MoveSnake();
    if(snake_->ObjectCollision(fruit_)) {
        ResetFruit();
        scene_->addItem(snake_->GrowSnake());
    }
    /*if(snake_->GameOver(scene_)) {
        qCritical() << "Game Over";
    }*/
    float timeout=speed_ * 1000;
    timer_->start(timeout);
}

void GameWindow::Setup()
{
    scene_ = new QGraphicsScene(ui->snake_game_);

    QBrush brush(QPixmap(":/pixmap/Background.png"));
    scene_->setBackgroundBrush(brush);

    scene_->setSceneRect(0,0,ui->snake_game_->width(),ui->snake_game_->height());

    snake_ = new Snake(ui->snake_game_->width() /2 - ui->snake_game_->width()/2 %32 + 16,ui->snake_game_->height() /2 - ui->snake_game_->height()/2 % 32 +16);
    scene_->addItem(snake_->Head());

}

void GameWindow::FruitPlacement()
{
    fruit_ = factory::CreateApple();
    fruit_->setScale(0.5);
    int tmp = rand() % ui->snake_game_->width();
    int w = tmp - tmp % 32;
    tmp = rand() % ui->snake_game_->height();
    int h = tmp - tmp % 32;
    fruit_->setPos(w-16, h-16);
    scene_->addItem(fruit_);
}

void GameWindow::ResetFruit()
{
    scene_->removeItem(fruit_);
    delete fruit_;
    FruitPlacement();
}
