#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include <QGraphicsItem>
#include <QObject>



class SnakeBody : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SnakeBody(QGraphicsItem *parent=0);
};

#endif // SNAKEBODY_H
