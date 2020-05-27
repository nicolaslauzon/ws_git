#ifndef SNAKEFACTORY_H
#define SNAKEFACTORY_H

#include <QGraphicsItem>


namespace factory
{
    QGraphicsItem *CreateApple();
    QGraphicsItem *CreateBody();
    QGraphicsItem *CreateHead();
    QGraphicsItem *CreateTitle();
}

#endif // SNAKEFACTORY_H
