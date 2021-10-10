#ifndef QUESTIONOBJ_H
#define QUESTIONOBJ_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QtWidgets>

class QuestionObj : public QObject
{
    Q_OBJECT
public:
    explicit QuestionObj(QObject *parent = nullptr);
    explicit QuestionObj(QJsonObject jsonQuestion);

    QString question;
    QString trueAnswer;
    QString falseAnswer;

    QJsonObject getRandomQuestionFromJsonDocument();
};

#endif // QUESTIONOBJ_H
