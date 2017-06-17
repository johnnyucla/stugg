#include "shell.h"
#include <QTimer>
#include <QGraphicsScene>
//#include <QDebug>
#include <QList>
#include <QObject>
#include "enemy.h"
#include "score.h"
#include "game.h"

extern Game * game;  //Creates an external object Game.

Shell::Shell() : QObject(), QGraphicsRectItem()
{
    //Draw the rect.
    setRect(0,0,5,10); //(x,y,width,height)

    //Connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(25);   //50 milli seconds
}

void Shell::move()
{
    //Check if shell collides with enemy, destroy both!
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

    //Move the shell up.
    setPos(x(),y()-10); //Don't forget, to go up, need to -10, not +10
    if (pos().y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
