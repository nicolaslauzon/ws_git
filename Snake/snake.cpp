#include "snake.h"

void Snake::RotateHead(Direction new_direction)
{
    switch (new_direction) {
        case Undefined:
            return;
            break;
        case North:
            head_->setRotation(-90);
            break;
        case West:
            head_->setRotation(180);
            break;
        case South:
            head_->setRotation(90);
            break;
        case East:
            head_->setRotation(0);
            break;
    }
}

QGraphicsItem *Snake::GrowSnake()
{
    direction_.push_back(direction_.back());
    int x = 0;
    int y = 0;
    if (!body_.empty()) {
        x = body_.back()->x();
        y = body_.back()->y();
    }
    else {
        x = head_->x();
        y = head_->y();
    }
    body_.push_back(factory::CreateBody());
    body_.back()->setPos(x,y);
    move(GetReverse(direction_.back()),body_.back());
    body_.back()->setScale(.5);
    return  body_.back();
}

 Direction Snake::GetReverse(const Direction direction)
{
    switch (direction) {
        case Undefined:
            break;
        case North:
            return South;
            break;
        case West:
            return East;
            break;
        case South:
            return North;
            break;
        case East:
            return West;
            break;

    }
    return Undefined;
}

void Snake::move(Direction direction, QGraphicsItem *to_move)
{
    switch (direction) {
        case Undefined:
            return;
            break;
        case North:
            to_move->setY(to_move->y()-32);
            break;
        case West:
            to_move->setX(to_move->x()-32);
            break;
        case South:
            to_move->setY(to_move->y()+32);
            break;
        case East:
            to_move->setX(to_move->x()+32);
            break;
    }
}

Snake::~Snake()
{
    if (head_!=nullptr)
        delete head_;
    // TODO delete the list
}

Snake::Snake(int w, int h)
{
    head_ = factory::CreateHead();
    direction_.push_back(East);
    head_->setScale(0.5);
    head_->setPos(w,h);
}

bool Snake::ObjectCollision(QGraphicsItem *object)
{
    if (object->y() == head_->y() && object->x() == head_->x()) {
        return true;
    }
    return false;
}

bool Snake::GameOver(QGraphicsScene *scene)
{
    if (! body_.empty()) {
        // test collision with the "body_"
        std::list<QGraphicsItem*>::const_iterator i = body_.cend();
        while (i != body_.begin()) {
            if(ObjectCollision(*i)) {
                return true;
            }
            ++i;
        }
        // test the collision with the walls
        if (       head_->x() - 16 == 0
                || head_->x() + 16 == scene->width()
                || head_->y() - 16 == 0
                || head_->y() + 16 == scene->height()) {
            return true;
        }
    }
    return false;
}

void Snake::MoveSnake()
{
    move(direction_.back(), head_);
    RotateHead(direction_.back());

    if(!body_.empty()) {
        std::list<Direction>::const_iterator i = direction_.end();
        std::list<QGraphicsItem*>::const_iterator j = body_.end();

        ++i;
        while(i != direction_.begin()) {
            move(*i, *j);
            ++j;
            ++i;
        }
        direction_.pop_front();
    }

}
