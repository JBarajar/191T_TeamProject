#ifndef RANDAI_H
#define RANDAI_H

#include<Model.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include<Trail.h>
#include <timer.h>
#include <Entity.h>
#include "Bike.h"

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

class randAI : public Bike
{
    public:
        randAI();
        virtual ~randAI();

        timer *A = new timer();     //Action timer
        textureLoader tloader;      //Loads bike image

        virtual void update(ObjectHandler* handler);

        void actions();          //Decide next action

        virtual void onCollision(Entity* collider);

    protected:

    private:
};

#endif // RANDAI_H
