/**
* \file JsonUtils.cpp
* \brief contains Json Utilities needed to access and modify Json files
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

#include "jsonutils.h"

JsonUtils::JsonUtils()
{
    //pathToJsonFile = "/home/eece435l/Documents/Project/qt-game-project/JSON/users.json";
    pathToJsonFile = QDir().absoluteFilePath("../qt-game-project/JSON/users.json");
    //qDebug()<<pathToJsonFile;
}

/**
 * \brief Gets the JsonDocument of the file path
 * \return QJsonDocument of the file path
*/
QJsonDocument JsonUtils:: getJsonDocument(){
    QFile file(this->pathToJsonFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray val = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(val);

    //for debugging purposes
    /*
    QJsonArray obj = jsonDocument.array();
    QJsonObject value = obj.at(0).toObject();
    qDebug()<<value.value("FirstName").toString();
    */

    return jsonDoc;
}
/**
 * \brief Takes a newly created user and appends it to the users.json document
 * \param User Object of type QJson Object
*/
void JsonUtils:: addUserToJson(QJsonObject user){
    QJsonDocument jsonDoc = getJsonDocument();
    QJsonArray users = jsonDoc.array();
    users.append(user);
    jsonDoc.setArray(users);
    QFile file(this->pathToJsonFile);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(jsonDoc.toJson());
    file.close();
}
/**
 * \brief Checks if a user who attempted to login has already signed up before
 * \param username, username of user
 * \param password, password of user
 * \return If the login was successful, returns the user as a QJsonObject.Else returns an empty QJSonObject
*/
QJsonObject JsonUtils::validateUser(QString &username, QString &password){
    QJsonDocument jsonDoc = getJsonDocument();
    QJsonArray users = jsonDoc.array();
    for(auto user : users){
        if(user.toObject().value("Username")==username && user.toObject().value("Password")==password){
            return user.toObject();
        }
    }
    return QJsonObject();
}

/**
 * @brief JsonUtils::updateScores, Update the User Scores in the Json object of the User
 * @param username, username of User
 * @param scores, scores Arraylist of user
 * @param highscore, User's Highscore
 * @param gameIdentifier, 0 for game1 and 1 for game2
 */
void JsonUtils::updateScores(QString username, QVector<int> scores, int highscore, int gameIdentifier){
    QJsonDocument jsonDoc = getJsonDocument();
    QJsonArray users = jsonDoc.array();

    QJsonArray scoresArray;
    for(int i : scores){
        scoresArray.append(i);
    }

    QString game = (gameIdentifier==0)? "game1":"game2";

    for(int i=0;i<users.count();i++){
        if(users.at(i).toObject().value("Username")==username){
            QJsonObject userObj = users.at(i).toObject();
            userObj[game+"_score"] = scoresArray;
            userObj[game+"_highScore"] = highscore;
            users.removeAt(i);
            users.insert(i,userObj);
            jsonDoc.setArray(users);
            break;
        }
    }
    QFile file(this->pathToJsonFile);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(jsonDoc.toJson());
    file.close();
}
/**
 * @brief JsonUtils::encodeProfilePicture, Takes a picture, encodes it, and returns the corresponding hashed QJsonValue
 * @param p, picture
 * @return QJsonValue for the encoded image
 */
QJsonValue JsonUtils::encodeProfilePicture(QPixmap &p){
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    p.save(&buffer, "PNG");
    auto const encoded = buffer.data().toBase64();
    return {QLatin1String(encoded)};
}

/**
 * @brief JsonUtils::decodeProfilePicture, Takes a QJsonValue corresponding to a picture, decodes it, and returns the corresponding QPixmap
 * @param pic
 * @return QJsonValue for the decoded image
 */
QPixmap JsonUtils::decodeProfilePicture(QJsonValue pic){
  auto const encoded = pic.toString().toLatin1();
  QPixmap p;
  p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
  return p;
}
