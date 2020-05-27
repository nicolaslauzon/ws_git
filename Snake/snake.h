#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>
#include <QGraphicsScene>

#include "snakefactory.h"

enum Direction {
    Undefined = 0,
    North = 1,
    West = 2,
    South = 3,
    East = 4
};

class Snake : public QGraphicsItemGroup
{
    std::list<Direction> direction_;
    std::list<QGraphicsItem*> body_;
    QGraphicsItem *head_;


    void move(Direction direction, QGraphicsItem *to_move);
    void RotateHead(Direction new_direction);

    Direction GetReverse(const Direction direction);
public:
    QGraphicsItem* GrowSnake();
    Snake(int w=0, int h=0);
    virtual ~Snake() override;
    QGraphicsItem* Head() {return head_;}
    bool ObjectCollision(QGraphicsItem *fruit);
    bool GameOver(QGraphicsScene *scene);
    void MoveSnake();

    void SetDirection(Direction direction) {direction_.back() = direction;}
    const Direction& TopDirection() {return direction_.back();}
};

#endif // SNAKE_H
