#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "GLScene.h"

class SceneHandler;

class gameScene : public GLScene
{
    public:
        gameScene();
        virtual ~gameScene();
        SceneHandler* shandler;

    protected:

    private:
};

#endif // GAMESCENE_H
