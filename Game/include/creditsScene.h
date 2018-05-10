#ifndef CREDITSSCENE_H
#define CREDITSSCENE_H

#include "GLScene.h"
#include "Model.h"
#include "parallax.h"

class SceneHandler;

class creditsScene : public GLScene
{
    public:
        creditsScene();
        virtual ~creditsScene();
        virtual GLint initGL();
        virtual GLint run();
        virtual GLint drawGLScene();
        virtual int windMsg(HWND,UINT, WPARAM,LPARAM);
        void processSelection();

        SceneHandler* shandler;

    protected:

    private:
};

#endif // CREDITSSCENE_H
