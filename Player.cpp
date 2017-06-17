#include "Player.h"
#include <QKeyEvent>
//#include <QMouseEvent>
#include "shell.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QObject>
#include "game.h"
#include <qmath.h>

extern Game* game;

Player::Player()
{
     setRect(0,0,100,25); //(x,y,length,width)
}

void Player::fire()
{
    //Create a shell.
    Shell* shell1 = new Shell();
    Shell* shell2 = new Shell();
    Shell* shell3 = new Shell();
    shell1->setPos(x()+25,y());
    shell2->setPos(x()+50,y());
    shell3->setPos(x()+85,y());
    scene()->addItem(shell1);
    scene()->addItem(shell2);
    scene()->addItem(shell3);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        if(pos().x() > 0)   //Binds the player in the window
        {
            setRotation(00);
            setPos(x()-5,y());
        }
    }
    else if(event->key() == Qt::Key_S)
    {
        if(pos().x() + 100 < 1066)
        {
            setPos(x()+5,y());
        }
    }
    else if(event->key() == Qt::Key_D)
    {
        if(pos().y() > 0)
        {
            setPos(x(),y()-5); //Grid inverted, must do -10 to go up.
        }

    }
    else if(event->key() == Qt::Key_A)
    {
        if(pos().y()+100 < 600)
        {
            setPos(x(),y()+5);
        }
    }

    else if(event->key() == Qt::Key_E)
    {
        if (pos().x() > 0 && pos().y() > 0)
        {  
            setRotation(15);
            setPos(x()-5,y()-5); //Grid inverted, must do -10 to go up.
        }
    }

    else if(event->key() == Qt::Key_C)
    {
        if(pos().x() + 100 < 1066 && pos().y() > 0)
        {
            double length = 5;
            double theta = rotation();  //Degress

            //Will need qmath.h for this.
            double dx = length*qCos(qDegreesToRadians(theta));  //Converts to radians because that is what the Cos function takes.
            double dy = length*qSin(qDegreesToRadians(theta));  //Converts to radians because that is what the Cos function takes.

            setRotation(-15);
            setPos(x()+dx,y()+dy);  //Moving
            setPos(x()+5,y()-5); //Grid inverted, must do -10 to go up.
        }
    }
    else if(event->key() == Qt::Key_Q)
    {
        if (pos().x() > 0 && pos().y() > 0)
        {
            setRotation(-15);
            setPos(x()-5,y()+5); //Grid inverted, must do -10 to go up.
        }
    }
    else if(event->key() == Qt::Key_Z)
    {
        if(pos().x() + 100 < 1066 && pos().y() > 0)
        {
            double length = 5;
            double theta = rotation();  //Degress

            //Will need qmath.h for this.
            double dx = length*qCos(qDegreesToRadians(theta));  //Converts to radians because that is what the Cos function takes.
            double dy = length*qSin(qDegreesToRadians(theta));  //Converts to radians because that is what the Cos function takes.

            setRotation(15);
            setPos(x()+dx,y()+dy);  //Moving
            setPos(x()+5,y()+5); //Grid inverted, must do -10 to go up.
        }
    }


    else if(event->key() == Qt::Key_Enter)
    {
        fire();
    }
    else if(event->key() == Qt::Key_Space)
    {
         qDebug() << "SPACE";
         fire();
    }
}

void Player::mousePressEvent(QMouseEvent *event)
{
    fire();

}

void Player::spawn()
{
    //Create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
