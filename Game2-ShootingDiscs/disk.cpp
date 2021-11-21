#include "disk.h"
/**
* \file Disk.cpp
* \brief contains initialization of a disk object.
*
* \author Karim Zarzour
* \author Maarouf Yassine
*/
Disk::Disk(QObject *parent, int gameSpeed) : QObject(parent)
{
    this->gameSpeed=gameSpeed;

    type = rand()%3;
    if(type ==0){
        this->setPixmap((QPixmap(":/images/red-disk.png")).scaled(30,30));
        setPos(140,200);
    }
    else if(type ==1){
        this->setPixmap((QPixmap(":/images/green-disk.jpg")).scaled(30,30));
        setPos(235,200);
    }
    else{
        this->setPixmap((QPixmap(":/images/blue-disk.png")).scaled(30,30));
        setPos(332,200);
    }


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(500);
}
/**
 * @brief Disk:: update, updates the position of a disk according to the current game speed
 */
void Disk:: update(){
    this->setPos(this->x(),this->y()+10*(gameSpeed+1));
}
