#include <QFont>

#include "Score.h"

Score::Score(QGraphicsItem *parent)
: QGraphicsTextItem(parent)
{
    //initialize the score to 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase(){
    score++;
    //redraw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

int Score::getScore(){
    return score;
}
