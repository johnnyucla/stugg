#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QObject>

class Health : public QGraphicsTextItem
{
    Q_OBJECT
    public:
        Health(QGraphicsItem* parent = 0);
        void decrease();
        void ramDecrease();
        void checkHealth();
        int getHealth();
    public slots:
        //void sunk();

    private:
        int health;
};

#endif // HEALTH_H
