#ifndef TURRET_H
#define TURRET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class Turret : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Turret(QGraphicsItem* parent = 0);
    double distanceTo(QGraphicsItem* item);
    void launch_rocket();
public slots:
   void get_target();
private:
    QGraphicsPolygonItem* attack_area;
    QPointF target_destination;    //needs to connect, so add Q_OBJECT
    bool has_target;
};

#endif // TURRET_H
