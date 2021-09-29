#include "jsonutils.h"

JsonUtils::JsonUtils()
{
    pathToJsonFile = "/home/eece435l/Documents/Project/qt-game-project/JSON/users.json";
}

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

QJsonValue JsonUtils::encodeProfilePicture(QPixmap &p){
    QBuffer buffer;
    buffer.open(QIODevice::WriteOnly);
    p.save(&buffer, "PNG");
    auto const encoded = buffer.data().toBase64();
    return {QLatin1String(encoded)};
}

QPixmap JsonUtils::decodeProfilePicture(QJsonValue pic){
  auto const encoded = pic.toString().toLatin1();
  QPixmap p;
  p.loadFromData(QByteArray::fromBase64(encoded), "PNG");
  return p;
}
