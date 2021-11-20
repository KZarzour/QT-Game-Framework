#ifndef GAME2GAMEPAGE_H
#define GAME2GAMEPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QtWidgets>
#include "lowerpanelbutton.h"
#include "disk.h"
#include <string>
#include "../Accounts_Framework/user.h"
#include "misseddiskzone.h"
#include "../Accounts_Framework/jsonutils.h"

/**
* \file Game2GamePage.h
* \brief Game2GamePage class
*/

class Game2GamePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game2GamePage();

    JsonUtils *jsonUtils;

    QGraphicsPixmapItem *leftArrow;
    QGraphicsPixmapItem *downArrow;
    QGraphicsPixmapItem *rightArrow;

    QGraphicsPixmapItem *gameGrid;

    QPushButton *home;

    QLabel *currentScore;
    QLabel *highScore;
    QLabel *currentScoreValue;
    QLabel *highScoreValue;
    QLabel *missedDisks;
    QLabel *missedDisksValue;
    QLabel *gameResult;

    LowerPanelButton *redButton;
    LowerPanelButton *greenButton;
    LowerPanelButton *blueButton;

    missedDiskZone *mdz;

    bool endGame = false;

    Disk *diskItem;

    User *activeUser = NULL;

    QTimer *timer;

    int currentUserScore;
    int highestScore;
    int currentMissedDisks;

    int gameSpeed;

    void setupScene();
    void setupWidgets();
    void setupGrid();
    void setupButtons();
    void setupLabels();
    void fillScene();
    void start();
    void incrementScore(int n);
    void incrementMisses();
    void finishGame();
    void interuptGame();


public slots:
    void addDisk();
    void checkMissedDisks();


};

#endif // GAME2GAMEPAGE_H
