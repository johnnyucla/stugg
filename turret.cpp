#include "turret.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "rocket.h"
#include <QLineF>
#include "game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>
//#include <qmath.h>
#include "enemy.h"
#include <QGraphicsScene>

/*I used QPointF, QPolygonF, and QLineF because they have member functions built in
 * and are generally more precise because they use doubles.
 */

extern Game* game;

Turret::Turret(QGraphicsItem *parent) : QGraphicsRectItem(), QObject()
{
    setRect(0,0,200,100);

    QVector<QPointF> points;    //Has << overloaded as a push_back from console.
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1)
           << QPoint(3,2) << QPoint(2,3) << QPoint(1,3)
           << QPoint(0,2)<< QPoint(0,1);

    //By default, a polygon is small.  Make it bigger.
    //Scale the points.
    int scale = 250;
    for (int i = 0, n = points.size(); i < n; ++i)
    {
        points[i] *= scale;
    }

    //Create a poygon from these points.  #include <QPolygonF>.
    //QPolygonF polygon(points);

    //Create the QGraphicsPolygonItem.
    attack_area = new QGraphicsPolygonItem(QPolygonF(points), this);  //this is a parent
    attack_area->setPen(QPen(Qt::DotLine));

    //Polygon not centered.  Use dx, dy to fix.
    //Move the polygon.
    //Find the center of the polygon.
    QPointF center(1.5,1.5);
    center *= scale;
    center = mapToScene(center);
    QPointF turret_center(x()+65, y()+65);   //Find out your pic size

    QLineF line(center, turret_center);
    attack_area->setPos(x()+line.dx(), y()+line.dy());

    //Connect a timer to get_target.
    QTimer * launch = new QTimer();
    connect(launch,SIGNAL(timeout()),this,SLOT(get_target()));
    launch->start(1000);

    //target_destination = QPointF(0,0);   //try to change this to the enemy.
}

double Turret::distanceTo(QGraphicsItem *item)
{
    QLineF line(pos(), item->pos());
    return line.length();
}


void Turret::launch_rocket()
{
    Rocket* rocket = new Rocket();
    rocket->setPos(x()+65, y()+65);

    //Rotate the rocket.
    QLineF line(QPointF(x()+65,y()+65),target_destination);

    //We need to multiply the angle by -1 because the angles are always counter clockwise.
    int angle = (-1)*line.angle();

    rocket->setRotation(angle);
    game->scene->addItem(rocket);
    //Now it needs to be connected.
}

void Turret::get_target()
{
    //Get a list of all items colliding with the polygon
       QList<QGraphicsItem*> colliding_items = attack_area->collidingItems();

       if (colliding_items.size() == 1)
       {
           has_target = false;  //There are no targets.  And break out.
           return;
       }

       double closest_distance = 300;
       QPointF closest_point = QPointF(0,0);

       for (int i = 0, n = colliding_items.size(); i < n; ++i)
       {
           Enemy* enemy = dynamic_cast<Enemy*>(colliding_items[i]);

           if(enemy)
           {
               double distance = distanceTo(enemy);

               if (distance < closest_distance)
               {
                   closest_distance = distance;
                   closest_point = colliding_items[i]->pos();
                   has_target = true;
               }
           }
       }
       target_destination = closest_point;
       launch_rocket();
}
