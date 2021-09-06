#include <QFont>

#include "Health.h"
#include "Game.h"

extern Game* game;

Health::Health(QGraphicsItem *parent)
: QGraphicsTextItem(parent)
{
    //initialize the score to 0
    health = 3;

    //draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    //redraw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    if(health < 0)
        game->close();
}

int Health::getHealth(){
    return health;
}
