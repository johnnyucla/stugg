#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "score.h"
#include "health.h"
#include "basehealth.h"
#include <QMouseEvent>
#include <QGraphicsView>
#include<QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "instr.h"

/* By JOHNNY ODABASHYAN
 * UCLA ID 104844369
 * PIC 10C SPRING 2017
 */

class Game : public QGraphicsView
{
    Q_OBJECT

    public:
        Game(QWidget* parent = 0);

        QGraphicsScene* scene;
        Player* player;
        Score* score;
        Health* health;
        BaseHealth* b_health;
        Instructions* inst;
      /*  void setCursor();
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);*/
        void displayMenu();
    public slots:
        void start();
        void end();
};

#endif // GAME_H
