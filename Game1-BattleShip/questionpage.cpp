#include "questionpage.h"

/**
* \file QUestionPage.cpp
* \brief contains initialization of a question page.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

QuestionPage::QuestionPage(QWidget *parent) : QWidget(parent)
{

    questionL = new QLabel();
    correctAnswerPB = new QPushButton();
    wrongAnswerPB = new QPushButton();

    vlayout = new QVBoxLayout();
    vlayout->addWidget(questionL);
    vlayout->addWidget(correctAnswerPB);
    vlayout->addWidget(wrongAnswerPB);

    setLayout(vlayout);

    generateQuestion();
}

/**
 * @brief QuestionPage::generateQuestion, generates a new question object and updates the question page accordingly
 */
void QuestionPage:: generateQuestion(){
    QuestionObj *question = new QuestionObj();
    questionL->clear();
    correctAnswerPB->setText("");
    wrongAnswerPB->setText("");
    questionL->setText(question->question);
    correctAnswerPB->setText(question->trueAnswer);
    wrongAnswerPB->setText(question->falseAnswer);
    correctAnswerPB->setEnabled(true);
    wrongAnswerPB->setEnabled(true);
    this->setStyleSheet("background-color: white;");
}
