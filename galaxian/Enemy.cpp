#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //rand()
#include <QDebug>

#include "Enemy.h"
#include "Game.h"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent)
: QObject(), QGraphicsPixmapItem(parent)
{
    //set random pos
    int random_number = rand() % 700;
    setPos(random_number, -100);


    //drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    //connect
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

   timer->start(50);
}


Enemy::~Enemy(){}

void Enemy::move(){
    // move enemy down
    setPos(x(), y() + 5);
    if(pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
