#include <QApplication>

#include "Game.h"

/*
 -QGraphicsScene
    container for all game obj.(as map of world)

 -QGraphicsItem(QGraphicsRectItem)
    only QGraphItems can go inside the scene (abstact class)

 -QGraphicsView
    visualize items in the scese
 - events(keyPressEvent() and QKeyEvent - stores info about the event)\
 - event propogation system - describes the order in witch the ivent was passed around
 -QDebug - print messages to the console

 -QGraphicsView coordinates vs QGraphicsScene coordinates vs QGraphicsItem coordinates

 */

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->show();

    return a.exec();
}
