#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class Button : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(QString name, QGraphicsItem* parent = 0);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void clicked(); //Don't need to define.
private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
