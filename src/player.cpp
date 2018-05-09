#include <player.h>
#include <iostream>

player::player()
{
    //ctor

    trail->setColor(0.0,0.5,0.5);

    Xpos = 0.5;
    Ypos = 0.0;


}

player::~player()
{
    //dtor
}


void player::update(ObjectHandler* handler)
{
    lastXpos = Xpos;
    lastYpos = Ypos;
    moveBike();

    trail->setSpeed(speed);
    trail->updateEnds(Xpos,Ypos);
}
