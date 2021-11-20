#ifndef DISK_H
#define DISK_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "lowerpanelbutton.h"
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItem>
#include<QDebug>

/**
* \file Disk.h
* \brief Disk class
*/

class Disk : public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Disk(QObject *parent = nullptr,int gameSpeed=0);

    int type;
    int gameSpeed=0;
public:
    QTimer *timer;

private slots:
    void update();
};

#endif // DISK_H
