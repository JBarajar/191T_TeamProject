#include "randAI.h"
#include "ObjectHandler.h"
#include <iostream>

randAI::randAI()
{
    //ctor

    trail->setColor(1.0,0.0,0.0);

    Xpos = -0.5;
    Ypos = 0.0;

    collider->setHeight(0.06f);
    collider->setWidth(0.06f);
    collider->setTag("bike");

    cols = new vector<BoxCollider*>;
    cols2 = new vector<BoxCollider*>;

    cols->push_back(nCol); cols->push_back(wCol); cols->push_back(sCol); cols->push_back(eCol);
    cols2->push_back(nCol2); cols2->push_back(wCol2); cols2->push_back(sCol2); cols2->push_back(eCol2);

    for(int i = 0; i < cols->size(); i++) {
        cols->at(i)->setHeight(0.06f);
        cols->at(i)->setWidth(0.06f);
    }

    for(int i = 0; i < cols2->size(); i++) {
        cols2->at(i)->setHeight(0.06f);
        cols2->at(i)->setWidth(0.06f);
    }

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

void randAI::updateColliders()
{
    cols->at(0)->setPosition(Xpos,Ypos+speed); //N
    cols->at(1)->setPosition(Xpos-speed,Ypos); //W
    cols->at(2)->setPosition(Xpos,Ypos-speed); //S
    cols->at(3)->setPosition(Xpos+speed,Ypos); //E

    cols2->at(0)->setPosition(Xpos,Ypos+speed+speed); //N
    cols2->at(1)->setPosition(Xpos-speed-speed,Ypos); //W
    cols2->at(2)->setPosition(Xpos,Ypos-speed-speed); //S
    cols2->at(3)->setPosition(Xpos+speed+speed,Ypos); //E
}

void randAI::setDistance(int index, int value)
{
    dists[index] = value;
}


void randAI::actions()
{
    int rDir  = rand()%100;         //Random direction

    //Gets dir for right turn
    int rTurn = dir - 1;
    if (rTurn == -1)
        rTurn = 3;

    //Gets dir for left turn
    int lTurn = dir + 1;
    if (lTurn == 4)
        lTurn = 0;

    //Dists index for relative west probe
    int eIndex = dir - 1;
    if(eIndex == -1)
        eIndex = 3;

    //Dists index for relative east probe
    int wIndex = dir - 1;
    if(wIndex == 4)
        wIndex = 0;

    if((dists[dir] == 0) && (dists[wIndex] == 0) && (dists[eIndex] == 0)){        //Case: No near trails/walls
        if(rDir < 70)                               //70% chance to continue in same direction
            ; //Do nothing
        else if(rDir >= 85)                         //15% chance to turn left
            setDirection(lTurn);
        else                                        //15% chance to turn right
            setDirection(rTurn);
    } else if((dists[dir] >= dists[wIndex]) && (dists[dir] >= dists[eIndex])){    //Case: Nearest threat N aka Dists[dir]
        if((dists[eIndex] > dists[wIndex]))         //Next nearest threat E
            setDirection(lTurn);
        else if(dists[wIndex] > dists[eIndex])      //Next nearest threat W
            setDirection(rTurn);
        else if(rDir > 50)                          //Choose rand direction
            setDirection(lTurn);                    //50% chance to turn left
        else
            setDirection(rTurn);                    //50% chance to turn right
    } else if((dists[eIndex] > dists[dir]) && (dists[eIndex] > dists[wIndex])){   //Case: Nearest threat E aka Dists[eIndex]
        if((dists[dir] > dists[wIndex]))            //Next nearest threat N
            setDirection(lTurn);
        else if(dists[wIndex] > dists[dir])         //Next nearest threat W
            ; //Continue forward
        else if(rDir > 50)                          //Choose rand direction
            setDirection(lTurn);                    //50% chance to turn left
        else
            ; //Continue forward                    //50% chance to turn right
    } else if((dists[wIndex] > dists[dir]) && (dists[wIndex] > dists[eIndex])) {  //Case: Nearest threat W aka Dists[wIndex]
        if((dists[dir] > dists[eIndex]))            //Next nearest threat N
            setDirection(rTurn);
        else if(dists[eIndex] > dists[dir])         //Next nearest threat E
            ; //Continue forward
        else if(rDir > 50)                          //Choose rand direction
            setDirection(lTurn);                    //50% chance to turn left
        else
            ; //Continue forward                    //50% chance to turn right
    } else {
        ; //Accept fate. Crash is inevitable.
    }

    collider->setPosition(Xpos,Ypos);
}

void randAI::onCollision(Entity* collider)
{
    if(collider->getCollider()->getTag() == "bike") {
        active = false;
    }
    if(collider->getCollider()->getTag() == "wall") {
        active = false;
    }
}
