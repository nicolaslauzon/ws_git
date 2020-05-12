#include "snakehead.h"

SnakeHead::SnakeHead(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/pixmap/SnakeHead.png"));
}
