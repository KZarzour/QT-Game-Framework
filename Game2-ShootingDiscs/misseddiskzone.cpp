#include "misseddiskzone.h"
/**
* \file JsonUtils.cpp
* \brief contains initialization of the missed disk zone
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/
missedDiskZone::missedDiskZone(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/images/transparent.png")).scaled(300,500));
    setPos(100,800);
    hide();
}
