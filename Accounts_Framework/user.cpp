#include "user.h"

User::User(QObject *parent) : QObject(parent)
{

}

User::User(QJsonObject user){
    firstName = user["First Name"].toString();
    lastName = user["Last Name"].toString();
    username = user["Username"].toString();
    gender = user["Gender"].toString();
    dob = user["Date of Birth"].toString();
    phonenumber = user["Phone Number"].toString();
    password = user["Password"].toString();
    profilePicture = QJsonValue(user["Profile Picture"].toString());
    game1HighScore = user["game1_highScore"].toInt();
    game2HighScore = user["game2_highScore"].toInt();

    QVector<int> g1Socres;
    QJsonArray arr1 = user["game1_score"].toArray();
    for (int i = 0; i < arr1.size(); ++i) {
            g1Socres.append(arr1[i].toInt());
    }
    game1Scores = g1Socres;

    QVector<int> g2Socres;
    QJsonArray arr2 = user["game2_score"].toArray();
    for (int i = 0; i < arr2.size(); ++i) {
            g2Socres.append(arr2[i].toInt());
    }
    game2Scores = g2Socres;

}

QJsonObject User::userToJson(){
    QJsonObject obj;
    obj["First Name"] = firstName;
    obj["Last Name"] = lastName;
    obj["Username"] = username;
    obj["Gender"] = gender;
    obj["Date of Birth"] = dob;
    obj["Phone Number"]=phonenumber;
    obj["Password"] = password;
    obj["Profile Picture"] = profilePicture;
    obj["game1_highScore"] = this->game1HighScore;
    obj["game2_highScore"] = this->game2HighScore;
    obj["game1_score"] = scoresAsJsonArray(game1Scores);
    obj["game2_score"] = scoresAsJsonArray(game2Scores);
    return obj;
}

QJsonArray User::scoresAsJsonArray(QVector<int> &scores){
    QJsonArray scoresJson;
        for (int i: scores) {
             scoresJson.append(QJsonValue(i));
        }
        return scoresJson;
}

bool User::isUnique(){
    QJsonDocument jsonDoc = json.getJsonDocument();
    QJsonArray users = jsonDoc.array();
    for(auto user : users){
        if(user.toObject().value("Username") == username) {
            return false;
        }
    }
    return true;
}

bool User::isValid(){

    if(
        this->firstName.isEmpty() ||
        this->lastName.isEmpty() ||
        this->gender.isEmpty() ||
        this->username.isEmpty() ||
        this->dob.isEmpty() ||
        this->password.isEmpty() ||
        this->phonenumber.isEmpty()
        ) {
        return false;
    }
    return true;
}

QString User::findCorrespondingFlag(){

    QString phoneNumber=this->phonenumber;
    //qDebug()<<phoneNumber;
    int i =0;
    while (phoneNumber.at(i)!='-'){
        i++;
        //qDebug()<<i;
        //qDebug()<<phoneNumber.at(i);
    }

    QString code=phoneNumber.midRef(1,i-1).toString();
    //qDebug()<<code;
    QFile file(QDir().absoluteFilePath("../qt-game-project/JSON/Countries.json"));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray val = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(val);
    QJsonArray countries = jsonDoc.array();
    for(auto country : countries){
        if(country.toObject().value("Code")==code){
            return country.toObject().value("ISO").toString();
        }
    }
    return "";

}
