#ifndef RANDAI_H
#define RANDAI_H

#include<Model.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include<Trail.h>
#include <timer.h>

/*
    This AI will move randomnly favoring its current direction over turning.
    It will look 2 positions in move directions to help with decision making.
*/

typedef struct
{
    float x;
    float y;
    float z;
}AIvec;

class randAI:Model
{
    public:
        randAI();
        virtual ~randAI();

        float scalesize[3]={1.0,1.0,1.0};
        vec1 verticies[4];

        Trail* rAITrail = new Trail(1.0,0.0,0.0);             //Light trail
        timer *T = new timer();     //Step timer
        timer *A = new timer();     //Action timer
        textureLoader tloader;      //Loads bike image
        float speed = 0.01;         //Bike move speed
        int dir = 0;                //Bike direction (0,1,2,3)
                                    //Corresponds to (N,W,S,E)

        void rAIInit();             //Initialization
        void setDirection(int);     //Sets draw direction
        void drawRAI();             //Draw at each step
        void actions();          //Decide next action
        void moveRAI();             //Move at each step

    protected:

    private:
};

#endif // RANDAI_H
