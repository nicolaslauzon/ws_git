#include "snakefactory.h"

namespace factory
{
QGraphicsItem *
CreateApple()
{
    QGraphicsPixmapItem* new_apple=new QGraphicsPixmapItem(QPixmap(":/pixmap/Fruit.png"));
    QRectF bbox = new_apple->boundingRect();
    new_apple->setOffset(-bbox.width() * .5 , -bbox.height() * .5);
    return new_apple;
}

QGraphicsItem *CreateTitle()
{
    QGraphicsPixmapItem* new_title=new QGraphicsPixmapItem(QPixmap(":/pixmap/Snake.png"));
    return new_title;
}

QGraphicsItem *CreateHead()
{
    QGraphicsPixmapItem* new_head=new QGraphicsPixmapItem(QPixmap(":/pixmap/SnakeHead.png"));
    QRectF bbox = new_head->boundingRect();
    new_head->setOffset(-bbox.width() * .5 , -bbox.height() * .5);
    return new_head;
}

QGraphicsItem *CreateBody()
{
    QGraphicsPixmapItem* new_body=new QGraphicsPixmapItem(QPixmap(":/pixmap/SnakeBody.png"));
    QRectF bbox = new_body->boundingRect();
    new_body->setOffset(-bbox.width() * .5 , -bbox.height() * .5);
    return new_body;
}


}
