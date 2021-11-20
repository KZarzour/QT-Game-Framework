#ifndef LOWERPANELBUTTON_H
#define LOWERPANELBUTTON_H

#include <QObject>
#include <QWidget>
#include <QGraphicsPixmapItem>

/**
* \file LowerPanelButton.h
* \brief LowerPanelButton class
*/

class LowerPanelButton : public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
public:
    LowerPanelButton(QObject *parent = nullptr, int type = -1);
    int type;

};

#endif // LOWERPANELBUTTON_H
