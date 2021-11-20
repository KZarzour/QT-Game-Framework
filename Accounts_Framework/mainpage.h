#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QtWidgets>
#include <QDate>
#include <QGraphicsPixmapItem>
#include "Accounts_Framework/user.h"
#include "Accounts_Framework/jsonutils.h"

/**
* \file mainPage.h
* \brief mainPage class
*/

class mainPage : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit mainPage(QObject *parent = nullptr);

    User* activeUser = NULL;
    JsonUtils json;

    QLabel *welcomeL;
    QLabel *dateL;

    QGraphicsPixmapItem *game1Logo;
    QGraphicsPixmapItem *game2Logo;
    QGraphicsPixmapItem *userProfilePicture;
    QGraphicsPixmapItem *flag;

    QPushButton *game1B;
    QPushButton *game2B;
    QPushButton *homeB;

    QLabel *game1Scores;
    QLabel *game2Scores;

    void setupGameLogos();
    void setupWidgetLocations();
    void addProfilePicture();
    void adjustLabelAppearance();
    void fillScene();
    void updateScores();
    void clearPage();
    void setFlag();
};

#endif // MAINPAGE_H
