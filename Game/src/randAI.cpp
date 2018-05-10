#include "randAI.h"
#include "ObjectHandler.h"

randAI::randAI()
{
    //ctor

    trail->setColor(1.0,0.0,0.0);

    Xpos = -0.5;
    Ypos = 0.0;

    collider->setHeight(0.06f);
    collider->setWidth(0.06f);
    collider->setTag("bike");

    /*cols->push_back(nCol); cols->push_back(wCol); cols->push_back(sCol); cols->push_back(eCol);
    cols2->push_back(nCol2); cols2->push_back(wCol2); cols2->push_back(sCol2); cols2->push_back(eCol2);

    for(auto const& i: cols) {
        cols->at(i)->setHeight(0.06f);
        cols->at(i)->setWidth(0.06f);
    }

    for(auto const& i: cols2) {
        cols2->at(i)->setHeight(0.06f);
        cols2->at(i)->setWidth(0.06f);
    }*/

    A->start();

    image = "images/EBike.png";
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

void randAI::updateColliders(vector<BoxCollider*>* col)
{
    col->at(0)->setPosition(Xpos,Ypos+0.006f); //N
    col->at(1)->setPosition(Xpos-0.006f,Ypos); //W
    col->at(2)->setPosition(Xpos,Ypos-0.006f); //S
    col->at(3)->setPosition(Xpos+0.006f,Ypos); //E
}

void randAI::setDistances()
{
    updateColliders(cols);
    updateColliders(cols2);

    if(dir == 0) {      //N
        //Set NDist = N
        if( (cols2->at(0)->getTag() == "bike") || (cols2->at(0)->getTag() == "wall") ) {
            NDist = 2;
        } else if ( (cols->at(0)->getTag() == "bike") || (cols->at(0)->getTag() == "wall") ) {
            NDist = 1;
        } else {
            NDist = 0;
        }
        //Set WDist = W
        if( (cols2->at(1)->getTag() == "bike") || (cols2->at(1)->getTag() == "wall") ) {
            WDist = 2;
        } else if ( (cols->at(1)->getTag() == "bike") || (cols->at(1)->getTag() == "wall") ) {
            WDist = 1;
        } else {
            WDist = 0;
        }
        //Set EDist = E
        if( (cols2->at(3)->getTag() == "bike") || (cols2->at(3)->getTag() == "wall") ) {
            EDist = 2;
        } else if ( (cols->at(3)->getTag() == "bike") || (cols->at(3)->getTag() == "wall") ) {
            EDist = 1;
        } else {
            EDist = 0;
        }
    }
    else if(dir == 1) {   //W
        //Set NDist = W
        if( (cols2->at(1)->getTag() == "bike") || (cols2->at(1)->getTag() == "wall") ) {
            NDist = 2;
        } else if ( (cols->at(1)->getTag() == "bike") || (cols->at(1)->getTag() == "wall") ) {
            NDist = 1;
        } else {
            NDist = 0;
        }
        //Set WDist = S
        if( (cols2->at(2)->getTag() == "bike") || (cols2->at(2)->getTag() == "wall") ) {
            WDist = 2;
        } else if ( (cols->at(2)->getTag() == "bike") || (cols->at(2)->getTag() == "wall") ) {
            WDist = 1;
        } else {
            WDist = 0;
        }
        //Set EDist = N
        if( (cols2->at(0)->getTag() == "bike") || (cols2->at(0)->getTag() == "wall") ) {
            EDist = 2;
        } else if ( (cols->at(0)->getTag() == "bike") || (cols->at(0)->getTag() == "wall") ) {
            EDist = 1;
        } else {
            EDist = 0;
        }
    }
    else if(dir == 2) {  //S
        //Set NDist = S
        if( (cols2->at(2)->getTag() == "bike") || (cols2->at(2)->getTag() == "wall") ) {
            NDist = 2;
        } else if ( (cols->at(2)->getTag() == "bike") || (cols->at(2)->getTag() == "wall") ) {
            NDist = 1;
        } else {
            NDist = 0;
        }
        //Set WDist = E
        if( (cols2->at(3)->getTag() == "bike") || (cols2->at(3)->getTag() == "wall") ) {
            WDist = 2;
        } else if ( (cols->at(3)->getTag() == "bike") || (cols->at(3)->getTag() == "wall") ) {
            WDist = 1;
        } else {
            WDist = 0;
        }
        //Set EDist = W
        if( (cols2->at(1)->getTag() == "bike") || (cols2->at(1)->getTag() == "wall") ) {
            EDist = 2;
        } else if ( (cols->at(1)->getTag() == "bike") || (cols->at(1)->getTag() == "wall") ) {
            EDist = 1;
        } else {
            EDist = 0;
        }
    }
    else {              //E

    }
}

void randAI::actions()
{
    int rDir  = rand()%100;         //Random direction
    setDistances();

    //Gets dir for left turn
    int lTurn = dir - 1;
    if (lTurn == -1)
        lTurn = 3;

    //Gets dir for right turn
    int rTurn = dir + 1;
    if (rTurn == 4)
        rTurn = 0;

    if((NDist == 0) && (EDist == 0) && (WDist == 0)){   //Case: No near trails/walls
        //70% chance to continue in same direction
        if(rDir < 70)
            ; //Do nothing
        //15% chance to turn left
        else if(rDir >= 85)
            setDirection(lTurn);
        //15% chance to turn right
        else
            setDirection(rTurn);
    } else if((NDist > EDist) && (NDist > WDist)){      //Case: Nearest threat N
        if((EDist > WDist))         //Next nearest threat E
            setDirection(lTurn);
        else if(WDist > EDist)      //Next nearest threat W
            setDirection(rTurn);
        else if(rDir > 50)          //Choose rand direction
            setDirection(lTurn);    //50% chance to turn left
        else
            setDirection(rTurn);    //50% chance to turn right
    } else if((EDist > NDist) && (EDist > WDist)){      //Case: Nearest threat E
        if((NDist > WDist))         //Next nearest threat N
            setDirection(lTurn);
        else if(WDist > NDist)      //Next nearest threat W
            ; //Do nothing
        else if(rDir > 50)          //Choose rand direction
            setDirection(lTurn);    //50% chance to turn left
        else
            ; //Do nothing          //50% chance to continue
    } else if((WDist > NDist) && (WDist > EDist)) {     //Case: Nearest threat W
        if((NDist > EDist))         //Next nearest threat N
            setDirection(rTurn);
        else if(EDist > NDist)      //Next nearest threat W
            ; //Do nothing
        else if(rDir > 50)          //Choose rand direction
            setDirection(rTurn);    //50% chance to turn right
        else
            ; //Do nothing          //50% chance to continue
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

