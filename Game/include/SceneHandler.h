#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H


#include <Model.h>
//#include <Font.h>

class SceneHandler:Model
{
    public:
        SceneHandler();
        virtual ~SceneHandler();

        void init(float, float);
        void moveSelectionUP();
        void moveSelectionDown();
        void setPaused();
        void processSelection();
        void drawMainMenu();
        void draw();
        void reset();

        //Font *font;

        float depth;

        bool stateChange;
        int curState, prevState, mainMenu, playGame, pauseGame, gameOver;
        int selection, play, credits, quit;
};


#endif // SCENEHANDLER_H
