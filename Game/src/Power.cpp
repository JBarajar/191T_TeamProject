#include "Power.h"

Power::Power(float x, float y)
{
    //ctor
    Xpos = x;
    Ypos = y;

    image = "images/DCell.png";
    collider->setTag("power");
}

Power::~Power()
{
    //dtor
}
