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
};

#endif // MAINPAGE_H
