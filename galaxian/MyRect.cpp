#include <QKeyEvent>
#include <QGraphicsScene>

#include "MyRect.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

extern Game* game;

Player::Player(QGraphicsItem *parent)
: QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer;
    bulletsound->setMedia(QUrl("qrc:/sounds/pew.wav"));

    setPixmap(QPixmap(":/images/plane.png"));
}

void Player::keyPressEvent(QKeyEvent* event){

    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x() -10, y());
        return;
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
            setPos(x() +10, y());
        return;
    }
    else if(event->key() == Qt::Key_Space){
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + 45, y() - 10);
        scene()->addItem(bullet);

        //play bulletsoumd
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    // create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

}
