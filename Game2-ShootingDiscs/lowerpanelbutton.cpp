/**
* \file JsonUtils.cpp
* \brief contains initialization of the object representing lower panel buttons in the game.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/

#include "lowerpanelbutton.h"

LowerPanelButton::LowerPanelButton(QObject *parent, int type) : QObject(parent)
{
    this->type = type;
    if(type == 0){//red button
        setPixmap((QPixmap(":/images/left-arrow.jpg")).scaled(50,50));
        setPos(130,750);
    }
    if(type == 1){//green button
        setPixmap((QPixmap(":/images/down-arrow.jpg")).scaled(50,50));
        setPos(225,750);
    }
    if(type == 2){//blue button
        setPixmap((QPixmap(":/images/right-arrow.jpg")).scaled(50,50));
        setPos(325,750);
    }
}

