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

class Disk : public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Disk(QObject *parent = nullptr);

    int type;

public:
    QTimer *timer;

private slots:
    void update();
};

#endif // DISK_H
