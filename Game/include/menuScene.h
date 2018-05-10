#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "GLScene.h"
#include "Model.h"
#include "parallax.h"

class SceneHandler

class menuScene : public GLScene
{
    public:
        menuScene();
        virtual ~menuScene();
        virtual GLint initGL();
        virtual GLint run();
        virtual GLint drawGLScene();
        void moveSelectionUP();
        void moveSelectionDown();
        void processSelection();
        virtual int windMsg(HWND,UINT, WPARAM,LPARAM);

        SceneHandler* shandler;
        int selection, play, credits, quit;

    protected:

    private:
};

#endif // MENUSCENE_H
