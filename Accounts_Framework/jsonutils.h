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

    /**
     * \brief Takes a newly created user and appends it to the users.json document
     * \param User Object of type QJson Object
    */
    void addUserToJson(QJsonObject user);

    /**
     * @brief JsonUtils::updateScores, Update the User Scores in the Json object of the User
     * @param username, username of User
     * @param scores, scores Arraylist of user
     * @param highscore, User's Highscore
     * @param gameIdentifier, 0 for game1 and 1 for game2
     */
    void updateScores(QString username, QVector<int> scores, int highscore, int gameIdentifier);
    QJsonDocument getJsonDocument();

    /**
     * \brief Checks if a user who attempted to login has already signed up before
     * \param username, username of user
     * \param password, password of user
     * \return If the login was successful, returns the user as a QJsonObject.Else returns an empty QJSonObject
    */
    QJsonObject validateUser(QString &username, QString &password);

    /**
     * @brief JsonUtils::encodeProfilePicture, Takes a picture, encodes it, and returns the corresponding hashed QJsonValue
     * @param p, picture
     * @return QJsonValue for the encoded image
     */
    QJsonValue encodeProfilePicture(QPixmap &p);

    /**
     * @brief JsonUtils::decodeProfilePicture, Takes a QJsonValue corresponding to a picture, decodes it, and returns the corresponding QPixmap
     * @param pic
     * @return QJsonValue for the decoded image
     */
    QPixmap decodeProfilePicture(QJsonValue pic);

};

#endif // JSONUTILS_H
