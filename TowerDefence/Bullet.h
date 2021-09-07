#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem* parent = 0);
    double getMaxRange();
    void   setMaxRange(double rng);
    double getDistanceTravelled();
    void   setDistanceTravelled(double dist);
public slots:
    void move();
private:
    double maxRange;
    double distanceTravelled;
};

#endif // BULLET_H
