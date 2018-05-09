#include "Wall.h"

Wall::Wall(float w, float h)
{
    //ctor
    Xpos = 0.0;
    Ypos = 0.0;

    width = w;
    height - h;

    collider->setHeight(height);
    collider->setWidth(width);

    verticies[0].x = -width;verticies[0].y = -height;verticies[0].z = -1.0;
    verticies[1].x = width;verticies[1].y = -height;verticies[1].z = -1.0;
    verticies[2].x = width;verticies[2].y = height;verticies[2].z = -1.0;
    verticies[3].x = -width;verticies[3].y = height;verticies[3].z = -1.0;
}

Wall::~Wall()
{
    //dtor
}

void Wall::init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    tloader.bindTexture(image);
}


void Wall::onCollision(ObjectHandler* handler, Entity* collider)
{

}

void Wall::update(ObjectHandler* handler)
{

}

void Wall::draw(double dt)
{
    glColor3f(0.0,1.0,0.0);
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
}

