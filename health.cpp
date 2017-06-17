#include "health.h"
#include <QFont>
#include "game.h"
#include "button.h"


extern Game* game;

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to zero
    health = 100;

    //Draw the text
    setPlainText(QString("Ship Health: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("consolas", 16));
}

void Health::decrease()
{
    health -= 2;
    setPlainText(QString("Ship Health: ") + QString::number(health));
    if (health == 0)
    {
       //emit sunk();
        //QApplication::quit();
        //Quit button
        Button* quit_button = new Button(QString("You sunk!  Please exit."));
        int quit_x = 1066/2;
        int quit_y = 600/2;
        quit_button->setPos(quit_x,quit_y);
    }
}

void Health::ramDecrease()
{
    health -= 10;
    setPlainText(QString("Ship Health: ") + QString::number(health));
    if (health == 0)
    {
        //emit sunk();
         // QApplication::quit()

        //Quit button
        Button* quit_button = new Button(QString("You sunk!  Please exit."));
        int quit_x = 1066/2;
        int quit_y = 600/2;
        quit_button->setPos(quit_x,quit_y);
    }
}

void Health::checkHealth()
{
    if (health == 0)
    {
        //QApplication::quit();
        //game->scene->clear();
        //setPlainText(QString("Game over!  You sunk!"));
    }
}

int Health::getHealth()
{
    return health;
}
