#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "GLScene.h"
#include "Model.h"
#include "parallax.h"

class menuScene : public GLScene
{
    public:
        menuScene();
        virtual ~menuScene();
        virtual GLint initGL();
        virtual GLint run();
        virtual GLint drawGLScene();

    protected:

    private:
};

#endif // MENUSCENE_H
