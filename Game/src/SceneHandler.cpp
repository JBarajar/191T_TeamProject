#include "SceneHandler.h"
SceneHandler::SceneHandler()
{
    //font = new Font();
    mmScene->shandler = this;
    gmScene->shandler = this;
    cdScene->shandler = this;
}

SceneHandler::~SceneHandler()
{
    //dtor
}

void SceneHandler::init()
{
  
}

void SceneHandler::run(GLScene* crScene)
{
    crScene->run();
}

void SceneHandler::reset()
{
    curState  = mainMenu;
    prevState = mainMenu;
}
