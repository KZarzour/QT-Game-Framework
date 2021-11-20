#include "commandpanel.h"
/**
* \file commandPanel.cpp
* \brief contains initialization of the command panel in game 1.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/
commandPanel::commandPanel(QWidget *parent) : QWidget(parent)
{
    mainLabel=new QLabel("Enter Target to hit ex: 00 for 1st row 1st column, 12 for 2nd row third column etc.");

    confirmPB = new QPushButton("Confirm Target");
    targetLineEdit = new QLineEdit;
    vlayout = new QVBoxLayout;

    vlayout = new QVBoxLayout();
    vlayout->addWidget(mainLabel);
    vlayout->addWidget(targetLineEdit);
    vlayout->addWidget(confirmPB);

    setLayout(vlayout);

}
