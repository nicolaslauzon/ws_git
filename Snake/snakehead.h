#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include <QGraphicsItem>
#include <QPixmap>

class SnakeHead : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SnakeHead(QGraphicsItem *parent=0);
protected slots:
};

#endif // SNAKEHEAD_H
