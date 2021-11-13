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

class Game2GamePage : public QGraphicsScene
{
    Q_OBJECT
public:
    Game2GamePage();

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

    LowerPanelButton *redButton;
    LowerPanelButton *greenButton;
    LowerPanelButton *blueButton;

    bool endGame = false;

    Disk *diskItem;

    User *activeUser;

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

public slots:
    void addDisk();


};

#endif // GAME2GAMEPAGE_H
