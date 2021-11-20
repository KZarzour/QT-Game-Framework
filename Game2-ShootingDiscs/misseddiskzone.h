#ifndef MISSEDDISKZONE_H
#define MISSEDDISKZONE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

/**
* \file missedDiskZone.h
* \brief MissedDiskZone class
*/

class missedDiskZone: public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
public:
    missedDiskZone(QObject *parent = nullptr);
};

#endif // MISSEDDISKZONE_H
