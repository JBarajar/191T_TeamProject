#include "SpeedUp.h"

SpeedUp::SpeedUp(float x, float y)
{
    //ctor
    Xpos = x;
    Ypos = y;

    image = "images/SpdUp.png";
    collider->setTag("speed");
}

SpeedUp::~SpeedUp()
{
    //dtor
}
