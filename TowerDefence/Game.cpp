#include <QGraphicsScene>

#include "Game.h"
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include "BuildTowerIcon.h"

Game::Game(){
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);


    //set the scene
    setScene(scene);



    // create a tower
    Tower* t = new Tower();
    t->setPos(250,250);

    // set cursor
    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    //add the tower to the scene
    scene->addItem(t);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create enemy
    Enemy* enemy = new Enemy();
    scene->addItem(enemy);

    BuildTowerIcon* ic = new BuildTowerIcon();
    scene->addItem(ic);

}

void Game::setCursor(QString filename){
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }

    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event){
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::mousePressEvent(QMouseEvent *event){
    if(build){
        scene->addItem(build);
        build->setPos(event->pos());
        cursor = nullptr;
        build = nullptr;
    }else{
        QGraphicsView::mousePressEvent(event);
    }
}

