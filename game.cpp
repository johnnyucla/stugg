#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include "Player.h"
#include "enemy.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "turret.h"
#include "basehealth.h"
#include <QGraphicsTextItem>
#include "button.h"
#include "instr.h"

Game::Game(QWidget *parent) : QGraphicsView()
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1066,600);
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1066,600);
}

void Game::displayMenu()
{
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("PROTECT THE BASE!"));
    QFont titleFont("consolas",50);
    title->setFont(titleFont);

    int title_x = this->width()/2 - title->boundingRect().width()/2;
    int title_y = this->height()/2 - title->boundingRect().height()/2-100;
    title->setPos(title_x,title_y);
    scene->addItem(title);

    //Play button
    Button* play_button = new Button(QString("Play"));

    int play_x = this->width()/2 - play_button->boundingRect().width()/2;
    int play_y = this->height()/2 - play_button->boundingRect().height()/2;
    play_button->setPos(play_x,play_y);

    connect(play_button,SIGNAL(clicked()),this,SLOT(start()));

    scene->addItem(play_button);

    //Quit button
    Button* quit_button = new Button(QString("Quit"));
    int quit_x = this->width()/2 - quit_button->boundingRect().width()/2;
    int quit_y = this->height()/2 - quit_button->boundingRect().height()/2+72;
    quit_button->setPos(quit_x,quit_y);

    connect(quit_button,SIGNAL(clicked()),this,SLOT(close()));

    scene->addItem(quit_button);
}

void Game::start()
{
    scene->clear();

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1066,600);
    setScene(scene);

    inst = new Instructions();
    inst->setPos(inst->x()+850, inst->y());
    scene->addItem(inst);

    //Adding the player.
    player = new Player();    //New and custom rect
    scene->addItem(player);

    //Make the item focusable in order to be moveable.
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView* view = new QGraphicsView(scene);
    //view->setScene(scene);

    setFixedSize(1066,600);

    //Disable the scroll bar.
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Move the item.
    player->setPos(view->width()/2, view->height()-player->rect().height());

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);


    //Spawn Enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn()));



    timer->start(2000); //every 2 secs

    Turret* t1 = new Turret();
    t1->setPos(-140,500);
    scene->addItem(t1);

    b_health = new BaseHealth();
    b_health->setPos(b_health->x()+420, b_health->y()+570);
    scene->addItem(b_health);


    Turret* t2 = new Turret();
    t2->setPos(1000,500);
    scene->addItem(t2);
}

void Game::end()
{
    QApplication::quit();
}


