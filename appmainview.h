#ifndef APPMAINVIEW_H
#define APPMAINVIEW_H

#include <QObject>
#include <QGraphicsView>
#include "Accounts_Framework/jsonutils.h"

class AppMainView : public QGraphicsView
{
    Q_OBJECT
public:
    AppMainView();

    JsonUtils *jsonUtils;
};

#endif // APPMAINVIEW_H
