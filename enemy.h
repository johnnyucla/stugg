#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    public:
        Enemy();
        void efire();
    //Anything that has slots needs a QObject.
    public slots:
        void move();
};

#endif // ENEMY_H
