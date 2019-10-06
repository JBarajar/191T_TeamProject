#include "SceneHandler.h"
SceneHandler::SceneHandler()
{
    //font = new Font();
    mmScene->shandler = this;
    gmScene->shandler = this;
    cdScene->shandler = this;

    curScene = mmScene;
}

SceneHandler::~SceneHandler()
{
    //dtor
}

void SceneHandler::init()
{

}

void SceneHandler::run()
{
    curScene->run();
}
