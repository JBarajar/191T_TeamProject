#include "BoxCollider.h"
#include<gl/glut.h>
#include <iostream>

BoxCollider::BoxCollider(float width, float height, std::string tag)
{
    this->width = width;
    this->height = height;
    this->tag = tag;

    verticies[0].x = -width/2;verticies[0].y = -height/2;verticies[0].z = -1.0;
    verticies[1].x = width/2;verticies[1].y = -height/2;verticies[1].z = -1.0;
    verticies[2].x = width/2;verticies[2].y = height/2;verticies[2].z = -1.0;
    verticies[3].x = -width/2;verticies[3].y = height/2;verticies[3].z = -1.0;
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

void BoxCollider::drawCollider()
{
    verticies[0].x = -width/2;verticies[0].y = -height/2;verticies[0].z = -1.0;
    verticies[1].x = width/2;verticies[1].y = -height/2;verticies[1].z = -1.0;
    verticies[2].x = width/2;verticies[2].y = height/2;verticies[2].z = -1.0;
    verticies[3].x = -width/2;verticies[3].y = height/2;verticies[3].z = -1.0;
    //std::cout << xpos << " " << ypos << std::endl;

    glPushMatrix();

    glTranslated(xpos, ypos, 0);

    glColor3f(0.0,1.0,0.0);
    //glPointSize(10.0);

    glBegin(GL_QUADS);

    glVertex3f(verticies[0].x,verticies[0].y,verticies[0].z);
    glVertex3f(verticies[1].x,verticies[1].y,verticies[1].z);
    glVertex3f(verticies[2].x,verticies[2].y,verticies[2].z);
    glVertex3f(verticies[3].x,verticies[3].y,verticies[3].z);

    glEnd();
    glColor3f(1.0,1.0,1.0);
    glPopMatrix();
}
