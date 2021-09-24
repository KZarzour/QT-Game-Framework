#ifndef APPMAINVIEW_H
#define APPMAINVIEW_H

#include <QObject>
#include <QGraphicsView>
#include "Accounts_Framework/jsonutils.h"
#include "Accounts_Framework/user.h"
#include "Accounts_Framework/signuppage.h"

class AppMainView : public QGraphicsView
{
    Q_OBJECT
public:
    AppMainView();

    JsonUtils *jsonUtils;
    SignupPage *signupPage;
};

#endif // APPMAINVIEW_H
