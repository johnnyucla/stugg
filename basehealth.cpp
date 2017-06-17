#include "basehealth.h"
#include <QFont>
#include "game.h"
#include "button.h"

extern Game* game;

BaseHealth::BaseHealth(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //Initialize the score to zero
    base_health = 100;

    //Draw the text
    setPlainText(QString("Base Health: ") + QString::number(base_health));
    setDefaultTextColor(Qt::magenta);
    setFont(QFont("consolas", 16));
}

void BaseHealth::baseHealthdecrease()
{
    base_health -= 5;
    setPlainText(QString("Base Health: ") + QString::number(base_health));
    if (base_health == 0)
    {
        Button* quit_button = new Button(QString("Base destroyed!  Please exit."));
        int quit_x = 1066/2;
        int quit_y = 600/2;
        quit_button->setPos(quit_x,quit_y);
    }
}

void BaseHealth::baseDestroyed()
{
        game->scene->clear();
        setPlainText(QString("Base Destoyed!"));
        setDefaultTextColor(Qt::black);
        setFont(QFont("consolas", 50));
}

int BaseHealth::getBaseHealth()
{
    return base_health;
}
