#include "player2.h"

player2::player2()
{
    //ctor
    trail->setColor(0.0,0.5,0.0);

    Xpos = -0.8;
    Ypos = 0.0;

    image = "images/2Bike.png";
}

player2::~player2()
{
    //dtor
}

void player2::update(ObjectHandler* handler)
{
    lastXpos = Xpos;
    lastYpos = Ypos;
    moveBike();

    trail->setSpeed(speed);
    trail->updateEnds(Xpos,Ypos);
}
