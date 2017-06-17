#ifndef ROCKET_H
#define ROCKET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Rocket : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Rocket(QGraphicsItem* parent = 0);
public slots:
    void launch();  //Will be continously launched
};

#endif // ROCKET_H
