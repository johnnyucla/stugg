#ifndef TURRETHEALTH_H
#define TURRETHEALTH_H

#include <QGraphicsTextItem>

class BaseHealth : public QGraphicsTextItem
{
    public:
        BaseHealth(QGraphicsItem* parent = 0);
        void baseHealthdecrease();
        void baseDestroyed();
        int getBaseHealth();

    private:
        int base_health;
};

#endif // TURRETHEALTH_H
