#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include <QImage>

#include "Enemy.h"
#include "Game.h"

Game::Game(QWidget* parent){
    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    //make the newly created scene the scene to visualize(since Game is a QGraphicsView)
    // it cat be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //cleate the player
    player = new Player();
    player->setPos(400, 500);
    // make an item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the item to the scene
    scene->addItem(player);

    //create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health ->setPos(health->x(), health->y()+25);
    scene->addItem(health);


    //spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    //play bg music
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/Action-Rock.mp3"));
    music->play();

    show();
}
