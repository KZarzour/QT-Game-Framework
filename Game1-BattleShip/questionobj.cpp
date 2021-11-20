#include "questionobj.h"

/**
* \file QuestionObj.cpp
* \brief contains initialization of a question object.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

QuestionObj::QuestionObj(QObject *parent): QObject(parent)
{
    QJsonObject jsonQuestion = getRandomQuestionFromJsonDocument();
    question = jsonQuestion["Q"].toString();
    trueAnswer = jsonQuestion["T"].toString();
    falseAnswer = jsonQuestion["F"].toString();
}

QuestionObj::QuestionObj(QJsonObject jsonQuestion){
    question = jsonQuestion["Q"].toString();
    trueAnswer = jsonQuestion["T"].toString();
    falseAnswer = jsonQuestion["F"].toString();
}

QJsonObject QuestionObj::getRandomQuestionFromJsonDocument(){
    QString pathToJsonFile = QDir().absoluteFilePath("../qt-game-project/JSON/questions.json");
    QFile file(pathToJsonFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray val = file.readAll();
    file.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(val);
    QJsonArray questions = jsonDoc.array();
    int length = questions.size();
    int rnd = rand()%length;
    return questions.at(rnd).toObject();
}
