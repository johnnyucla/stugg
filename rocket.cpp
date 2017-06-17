#include "rocket.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include "game.h"
#include <QGraphicsRectItem>
#include <QObject>
#include "enemy.h"

extern Game* game;

Rocket::Rocket(QGraphicsItem *parent) : QGraphicsRectItem(), QObject()
{
    setRect(0,0,20,10);

    //Need a timer to connect in order to lanuch.
    QTimer* launch_timer = new QTimer(this);
    connect(launch_timer, SIGNAL(timeout()), this, SLOT(launch()));
    launch_timer->start(50);  //Slow intervals because it's lanuch a rocket.
}

void Rocket::launch()   //Pun very much intended
{
    //Launching at a straight angle.  Will need to use degrees.
    double length = 30;
    double theta = rotation();  //Degress

    //Will need qmath.h for this.
    double dx = length*qCos(qDegreesToRadians(theta));  //Converts to radians because that is what the Cos function takes.
    double dy = length*qSin(qDegreesToRadians(theta));  //Converts to radians because that is what the Cos function takes.

    setPos(x()+dx,y()+dy);  //Moving



    //Check if rocket collides with enemy, destroy both!
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //Increase the score.
            game->score->increase();

            //Remove them both.
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Delete them both to free the memory
            delete colliding_items[i];
            delete this;

            //This crashses the program

            return; //Crash fixed!
        }

    }

    //Move the rocket up.
    if (pos().y()+rect().height() < 0 || pos().x()+rect().width() > 1066)
    {
        scene()->removeItem(this);
        delete this;
       // qDebug() << "rocket deleted.";
    }
}
