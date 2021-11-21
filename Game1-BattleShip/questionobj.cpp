#include "questionobj.h"

/**
* \file QuestionObj.cpp
* \brief contains initialization of a question object.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/
/**
 * @brief QuestionObj::QuestionObj, initializes a question object randomly
 * @param parent
 */
QuestionObj::QuestionObj(QObject *parent): QObject(parent)
{
    QJsonObject jsonQuestion = getRandomQuestionFromJsonDocument();
    question = jsonQuestion["Q"].toString();
    trueAnswer = jsonQuestion["T"].toString();
    falseAnswer = jsonQuestion["F"].toString();
}
/**
 * @brief QuestionObj::QuestionObj, returns a question object from a json input.
 * @param jsonQuestion, question read fron json file
 */
QuestionObj::QuestionObj(QJsonObject jsonQuestion){
    question = jsonQuestion["Q"].toString();
    trueAnswer = jsonQuestion["T"].toString();
    falseAnswer = jsonQuestion["F"].toString();
}
/**
 * @brief QuestionObj::getRandomQuestionFromJsonDocument, chooses a question by random from the Json document containing questions
 * @return question of type questionObj
 */
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
