#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
//#include <QDebug>
#include <stdlib.h>
#include <QList>
#include <QObject>
#include "game.h"
#include "health.h"
#include "turret.h"
#include "basehealth.h"
#include "shell.h"
#include "rocket.h"

extern Game * game;  //Creates an external object Game.

Enemy::Enemy() : QObject(), QGraphicsRectItem()
{
    //Set a random position
    int random_number = rand()% 1100;
    setPos(random_number,0);
    //Draw the rect.
    setRect(0,0,20,60); //(x,y,width,height)

    //Connect
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);   //50 milli seconds
}

void Enemy::efire()
{
    //Shell* shell1 = new Shell();
    Rocket* rocket = new Rocket();
}

void Enemy::move()
{
    //game->health->checkHealth();

    //Move the enemy down.
    setPos(x(),y()+5); //Don't forget, to go up, need to -10, not +10


    if (pos().y() > 600)    //If the enemy ships reach the bottom
    {
        //Decrease the player health.
        game->b_health->baseHealthdecrease();


        scene()->removeItem(this);
        delete this;
    }

    else   //If you and the enemy ship collide
    {
        QList<QGraphicsItem *> ships = collidingItems();
        for (int i = 0, n = ships.size(); i < n; ++i)
        {
            if (typeid(*(ships[i])) == typeid(Player))
            {
                //Increase the score.
                game->health->ramDecrease();

                //Remove them both.

                scene()->removeItem(this);

                //Delete them both to free the memory

                delete this;

                //This crashses the program

                return; //Crash fixed!
            }
            else if (typeid(*(ships[i])) == typeid(Turret))
            {
                //Increase the score.
                game->b_health->baseHealthdecrease();
                game->b_health->baseHealthdecrease();

                //Remove them both.

                scene()->removeItem(this);

                //Delete them both to free the memory

                delete this;

                //This crashses the program

                return; //Crash fixed!
            }
        }
    }
}
