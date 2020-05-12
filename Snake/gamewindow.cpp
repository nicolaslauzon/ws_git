#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(int w, int h, int difficulty, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    ui->snake_game_->setFixedSize(w, h);
    Setup();
    FruitPlacement();
    ui->snake_game_->setScene(scene_);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::Setup()
{
    scene_ = new QGraphicsScene();
    QBrush brush(QPixmap(":/pixmap/Background.png"));
    scene_->setBackgroundBrush(brush);
    scene_->setSceneRect(0,0,ui->snake_game_->width(),ui->snake_game_->height());
    snake_head_ = new SnakeHead();
    snake_head_->setScale(0.5);
    snake_head_->setPos(ui->snake_game_->width() /2 - ui->snake_game_->width()/2 %32, ui->snake_game_->height() /2 - ui->snake_game_->height()/2 % 32);
    scene_->addItem(snake_head_);
}

void GameWindow::FruitPlacement()
{
    fruit_ = new Apple();
    fruit_->setScale(0.5);
    int tmp = rand() % ui->snake_game_->width();
    int w = tmp - tmp % 32;
    tmp = rand() % ui->snake_game_->height();
    int h = tmp - tmp % 32;
    fruit_->setPos(w, h);
    scene_->addItem(fruit_);
}
