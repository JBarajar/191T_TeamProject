#ifndef INPUTS_H
#define INPUTS_H

#include <windows.h>
#include <iostream>
#include <Model.h>
#include <parallax.h>
#include <player.h>
#include <player2.h>
#include <skyBox.h>
#include <GLScene.h>
#include <ObjectHandler.h>
#include "gameScene.h"
#include "menuScene.h"
#include "creditsScene.h"
#include "SceneHandler.h"

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed(Model *);
        void keyPressed(player *);
        void p2keyPressed(player2*);
        void keyPressed(skyBox *);
        void keyPressed(GLScene*);
        void keyPressed(ObjectHandler*);
        void keyPressed(menuScene*);
        void keyPressed(creditsScene*);

        void keyUp(player *);
        void keyUP();
        void keyEnv(parallax *, float); // movements of my background

        void mouseEventDown(Model *,double ,double);
        void mouseEventUp();
        void mouseWheel(Model *,double);
        void mouseMove(Model *,double ,double );
        void mouseMove(skyBox *,double ,double );

        double prev_Mouse_X;
        double prev_Mouse_Y;
        bool Mouse_Translate;
        bool Mouse_Roatate;



        WPARAM wParam;

    protected:

    private:
};

#endif // INPUTS_H
