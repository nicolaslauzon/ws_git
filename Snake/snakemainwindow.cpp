#include "snakemainwindow.h"

SnakeMainWindow::SnakeMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SnakeMainWindow)
{
     ui->setupUi(this);
     setSnakeImage();
}

SnakeMainWindow::~SnakeMainWindow()
{
    delete ui;
}

void SnakeMainWindow::StartGame()
{
    float difficulty = 1;

    if (ui->easy_btn_->isChecked()) {
        difficulty = 1;
    }
    else if (ui->intermediate_btn_->isChecked()) {
        difficulty = .5;
    }
    else if (ui->hard_btn_->isChecked()) {
        difficulty = .25;
    }

    int w = ui->width_lbl_->text().toInt();
    int h = ui->height_lbl_->text().toInt();
    w = w - w % 32;
    h = h - h % 32;
    GameWindow *game_window = new GameWindow(w, h, difficulty, this);

    game_window->setWindowTitle("Snake game");
    game_window->setModal(true);
    game_window->show();
}

void SnakeMainWindow::setSnakeImage()
{
    scene_ = new QGraphicsScene(ui->snake_img_);

    snake_head_ = factory::CreateHead();
    snake_body_ = factory::CreateBody();
    snake_body1_ = factory::CreateBody();
    snake_body2_ = factory::CreateBody();
    snake_body3_ = factory::CreateBody();
    apple_ = factory::CreateApple();
    title_ = factory::CreateTitle();

    snake_head_->setPos(ui->snake_img_->width()/2+96,ui->snake_img_->height()/2+62);
    snake_body_->setPos(ui->snake_img_->width()/2+32,ui->snake_img_->height()/2+62);
    snake_body1_->setPos(ui->snake_img_->width()/2-32,ui->snake_img_->height()/2+62);
    snake_body2_->setPos(ui->snake_img_->width()/2-32,ui->snake_img_->height()/2-2);
    snake_body3_->setPos(ui->snake_img_->width()/2-96,ui->snake_img_->height()/2-2);
    apple_->setPos(ui->snake_img_->width()/2+160,ui->snake_img_->height()/2+62);
    title_->setPos(ui->snake_img_->width()/2-112, 0);

    scene_->addItem(snake_head_);
    scene_->addItem(snake_body_);
    scene_->addItem(snake_body1_);
    scene_->addItem(snake_body2_);
    scene_->addItem(snake_body3_);
    scene_->addItem(apple_);
    scene_->addItem(title_);

    scene_->setSceneRect(0,0,ui->snake_img_->width(),ui->snake_img_->height());
    ui->snake_img_->setScene(scene_);
}

