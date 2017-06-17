#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMouseEvent>
#include <QKeyEvent>

class Player :  public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    public:
        Player();
        void fire();
        void keyPressEvent(QKeyEvent *event);
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
    public slots:
        void spawn();
};

#endif // PLAYER_H
