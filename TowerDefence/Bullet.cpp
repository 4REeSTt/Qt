#include <QTimer>
#include <QPixmap>
#include <qmath.h> // qSin, qCos, qTan...
#include <QtMath>

#include "Bullet.h"

Bullet::Bullet(QGraphicsItem *parent){
    //set graphics
    setPixmap(QPixmap(":/images/Arrow.png"));

    //connect a timer to move()
    QTimer* move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

    //initialize values
    maxRange = 100;
    distanceTravelled = 0;
}

double Bullet::getMaxRange()
{

}

void Bullet::setMaxRange(double rng)
{

}

double Bullet::getDistanceTravelled()
{

}

void Bullet::setDistanceTravelled(double dist)
{

}

void Bullet::move(){
    int STEP_SIZE = 30;
    double theta = rotation(); //degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
