#ifndef JSONUTILS_H
#define JSONUTILS_H

#include <QJsonDocument>
#include <QtWidgets>

/**
* \file JsonUtils.h
* \brief JsonUtils class
*/

class JsonUtils
{
public:
    JsonUtils();

    QString pathToJsonFile;

    void addUserToJson(QJsonObject user);
    void updateScores(QString username, QVector<int> scores, int highscore, int gameIdentifier);
    QJsonDocument getJsonDocument();
    QJsonObject validateUser(QString &username, QString &password);

    QJsonValue encodeProfilePicture(QPixmap &p);
    QPixmap decodeProfilePicture(QJsonValue pic);

};

#endif // JSONUTILS_H
