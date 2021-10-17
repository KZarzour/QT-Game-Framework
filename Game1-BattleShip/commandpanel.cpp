#include "commandpanel.h"

commandPanel::commandPanel(QWidget *parent) : QWidget(parent)
{
    mainLabel=new QLabel("Enter Target to hit ex: A1, B2 etc.");

    confirmPB = new QPushButton("Connfirm Target");
    targetLineEdit = new QLineEdit;
    vlayout = new QVBoxLayout;

    vlayout = new QVBoxLayout();
    vlayout->addWidget(mainLabel);
    vlayout->addWidget(targetLineEdit);
    vlayout->addWidget(confirmPB);
    setLayout(vlayout);

}
