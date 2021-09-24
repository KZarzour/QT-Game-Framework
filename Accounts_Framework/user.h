#ifndef USER_H
#define USER_H

#include <QObject>
#include "jsonutils.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    explicit User(QJsonObject user);

    bool isUnique();
    bool isValid();

    QJsonObject userToJson();
    QJsonArray scoresAsJsonArray(QVector<int> &scores);

    JsonUtils json;

    QString username;
    QString password;
    QString firstName;
    QString lastName;
    QString dob;
    QString gender;
    QString phonenumber;
    QJsonValue profilePicture;

    int game1HighScore=0;
    int game2HighScore=0;

    QVector<int> game1Scores={};
    QVector<int> game2Scores={};



signals:

};

#endif // USER_H
