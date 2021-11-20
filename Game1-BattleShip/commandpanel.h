#ifndef COMMANDPANEL_H
#define COMMANDPANEL_H

#include <QWidget>
#include <QObject>
#include <QtWidgets>

/**
* \file commandPanel.h
* \brief commanPanel class
*/

class commandPanel : public QWidget
{
    Q_OBJECT
public:
    explicit commandPanel(QWidget *parent = nullptr);
    QLabel * mainLabel;

    QPushButton * confirmPB;
    QLineEdit * targetLineEdit;

    QVBoxLayout *vlayout;

signals:

};

#endif // COMMANDPANEL_H
