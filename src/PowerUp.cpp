#include "PowerUp.h"
#include <iostream>

PowerUp::PowerUp(float x, float y)
{

    Xpos = x;
    Ypos = y;

    collider->setHeight(height);
    collider->setWidth(width);

    verticies[0].x = -width/2;verticies[0].y = -height/2;verticies[0].z = -1.0;
    verticies[1].x = width/2;verticies[1].y = -height/2;verticies[1].z = -1.0;
    verticies[2].x = width/2;verticies[2].y = height/2;verticies[2].z = -1.0;
    verticies[3].x = -width/2;verticies[3].y = height/2;verticies[3].z = -1.0;


}

PowerUp::~PowerUp()
{
    //dtor
}

void PowerUp::onCollision(ObjectHandler* handler, Entity* collider)
{

    if(collider->getCollider()->getTag() == "bike") {
        active = false;
    }
}

void PowerUp::init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    tloader.bindTexture(image);
    collider->setPosition(Xpos, Ypos);

    collider->setHeight(height);
    collider->setWidth(width);
}

void PowerUp::update(ObjectHandler*)
{

}

void PowerUp::draw(double)
{


    glColor3f(1.0,1.0,0.0);
    tloader.nullTex();
    glTranslated(Xpos, Ypos, 0.0);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);

        glTexCoord2f(1.0,1.0);
        glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);

        glTexCoord2f(1.0,0.0);
        glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);

        glTexCoord2f(0.0,0.0);
        glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);
    glEnd();
    tloader.nullTex();

    glColor3f(1.0,1.0,1.0);

    collider->drawCollider();
}

