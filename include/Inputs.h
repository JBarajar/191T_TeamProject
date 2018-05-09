#ifndef INPUTS_H
#define INPUTS_H

#include <windows.h>
#include <iostream>
#include <Model.h>
#include <parallax.h>
#include <player.h>
#include <skyBox.h>

class Inputs
{
    public:
        Inputs();
        virtual ~Inputs();

        void keyPressed(Model *);
        void keyPressed(player *);
        void keyPressed(skyBox *);

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
