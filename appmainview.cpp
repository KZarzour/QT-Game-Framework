#include "appmainview.h"

AppMainView::AppMainView()
{
    jsonUtils = new JsonUtils();
    signupPage = new SignupPage();

    this->close();

    signupPage->show();

    /*
    QJsonDocument doc = jsonUtils->getJsonDocument();
    QJsonArray users = doc.array();
    for(auto user : users){
        QJsonObject obj = user.toObject();
        qDebug()<<obj.value("FirstName").toString();
    }

    QJsonObject  recordObject;

    recordObject.insert("FirstName", QJsonValue::fromVariant("SJohn"));
    recordObject.insert("LastName", QJsonValue::fromVariant("DSoe"));
    recordObject.insert("Age", QJsonValue::fromVariant(431));

    jsonUtils->addUserToJson(recordObject);
    */
}
