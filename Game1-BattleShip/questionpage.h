#ifndef QUESTIONPAGE_H
#define QUESTIONPAGE_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include "questionobj.h"

class QuestionPage : public QWidget
{
    Q_OBJECT
public:
    QuestionPage(QWidget *parent = nullptr);

    QLabel * questionL;

    QPushButton * correctAnswerPB;
    QPushButton * wrongAnswerPB;

    QVBoxLayout *vlayout;

    void generateQuestion();
};

#endif // QUESTIONPAGE_H
