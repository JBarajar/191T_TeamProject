#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H

#include "GLScene.h"
#include "gameScene.h"
#include "menuScene.h"
#include "creditsScene.h"
//#include <Font.h>

class SceneHandler: public Model
{
    public:
        SceneHandler();
        virtual ~SceneHandler();

        void init();
        void run(GLScene*);
        void reset();

        GLScene *curScene = new GLScene();
        menuScene *mmScene = new menuScene();
        gameScene *gmScene = new gameScene();
        creditsScene *cdScene = new creditsScene();

        //Font *font;

        float depth;

};


#endif // SCENEHANDLER_H
