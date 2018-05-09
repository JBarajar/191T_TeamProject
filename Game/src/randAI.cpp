#include "randAI.h"

randAI::randAI()
{
    //ctor

    trail->setColor(1.0,0.0,0.0);

    Xpos = 3.0;
    Ypos = 1.0;

    A->start();
}

randAI::~randAI()
{
    //dtor
}

void randAI::update(ObjectHandler* handler)
{
    lastXpos = Xpos;
    lastYpos = Ypos;
    moveBike();
    trail->setSpeed(speed);
    trail->updateEnds(Xpos,Ypos);

    if(A->getTicks()>150){
        actions();
        A->reset();
    }
}

void randAI::actions()
{

    int rDir  = rand()%100;         //Random direction
    int NDist = 3;  //anyTrail.dist(North);
    int EDist = 3;  //anyTrail.dist(East);
    int WDist = 3;  //anyTrail.dist(West);

    //Gets dir for left turn
    int lTurn = dir - 1;
    if (lTurn == -1)
        lTurn = 3;

    //Gets dir for right turn
    int rTurn = dir + 1;
    if (rTurn == 4)
        rTurn = 0;

    //Case: No near trails/walls
    if((NDist > 2) && (EDist > 2) && (WDist > 2)){
        //70% chance to continue in same direction
        if(rDir < 70)
            ;//Do nothing
        //15% chance to turn left
        else if(rDir >= 85)
            setDirection(lTurn);
        //15% chance to turn right
        else
            setDirection(rTurn);
    }

}

void randAI::onCollision(Entity* collider)
{

}

