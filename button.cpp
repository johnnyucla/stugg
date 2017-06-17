#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

Button::Button(QString name, QGraphicsItem *parent) : QObject(), QGraphicsRectItem(parent)
{
    //Draw rect.
    setRect(0,0,200,50);
    //Change the color.
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    //Draw text
    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    //Allow responding to hover events.
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

