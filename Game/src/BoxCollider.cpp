#include "BoxCollider.h"

BoxCollider::BoxCollider(float width, float height, std::string tag)
{
    this->width = width;
    this->height = height;
    this->tag = tag;
}

BoxCollider::~BoxCollider()
{
    //dtor
}

void BoxCollider::setPosition(float x, float y)
{
    xpos = x;
    ypos = y;
}


