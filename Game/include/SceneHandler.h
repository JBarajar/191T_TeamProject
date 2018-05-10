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

        void init(float, float);
        void moveSelectionUP();
        void moveSelectionDown();
        void setPaused();
        void processSelection();
        void run();
        void reset();

        GLScene *curScene = new GLScene();
        menuScene *mmScene = new menuScene();
        gameScene *gmScene = new gameScene();
        creditsScene *cdScene = new creditsScene();

        //Font *font;

        float depth;

        bool stateChange;
        int curState, prevState, mainMenu, playGame, pauseGame, gameOver, gameCredits;
        int selection, play, credits, quit;

};


#endif // SCENEHANDLER_H
