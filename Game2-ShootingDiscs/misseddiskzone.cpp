#include "misseddiskzone.h"

missedDiskZone::missedDiskZone(QObject *parent) : QObject(parent)
{
    setPixmap((QPixmap(":/images/transparent.png")).scaled(300,500));
    setPos(100,800);
}
