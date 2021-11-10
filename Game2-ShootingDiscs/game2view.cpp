#include "game2view.h"

Game2View::Game2View()
{
    activeUser = new User();
    jsonUtils = new JsonUtils();

    this->setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    this->setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));

}
