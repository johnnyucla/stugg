#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "Player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "game.h"
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    game->displayMenu();

    return a.exec();
}
