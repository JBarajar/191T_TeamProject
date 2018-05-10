#include "Bike.h"
#include "ObjectHandler.h"

Bike::Bike()
{
    //ctor
    verticies[0].x = -width/2;verticies[0].y = -height/2;verticies[0].z = -1.0;
    verticies[1].x = width/2;verticies[1].y = -height/2;verticies[1].z = -1.0;
    verticies[2].x = width/2;verticies[2].y = height/2;verticies[2].z = -1.0;
    verticies[3].x = -width/2;verticies[3].y = height/2;verticies[3].z = -1.0;

    collider->setHeight(cheight);
    collider->setWidth(cwidth);
    collider->setTag("bike");
}

Bike::~Bike()
{
    //dtor
}

void Bike::init()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    tloader.bindTexture(image);

    trail->init(Xpos, Ypos);
}

void Bike::setDirection(int d)
{
    if(dir == 0 && d == 2 || dir == 1 && d == 3 || d == 0 && dir == 2 || d == 1 && dir == 3 || dir == d) {

    }
    else {
        dir = d;
        rot = 90*dir;
        trail->addPoint();
    }
}

void Bike::moveBike()
{
    switch(dir) {
    case 0:
        Ypos += speed;
        collider->setHeight(cheight);
        collider->setWidth(cwidth);
        break;
    case 1:
        Xpos -= speed;
        collider->setWidth(cheight);
        collider->setHeight(cwidth);
        break;
    case 2:
        Ypos -= speed;
        collider->setHeight(cheight);
        collider->setWidth(cwidth);
        break;
    case 3:
        Xpos += speed;
        collider->setWidth(cheight);
        collider->setHeight(cwidth);
        break;
    }

    collider->setPosition(Xpos,Ypos);
}

void Bike::draw(double dt)
{
    glPushMatrix();
        trail->drawTrail();
    glPopMatrix();

    glPushMatrix();

    //collider->drawCollider();

    glTranslated(Xpos,Ypos,0.0);
    glRotated(dir * 90, 0,0,1);

    tloader.binder();

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

    glPopMatrix();
}

void Bike::update(ObjectHandler* handler)
{

}

void Bike::onCollision(ObjectHandler* handler, Entity* collider)
{
    if(collider->getCollider()->getTag() == "bike") {
        active = false;
    }
    if(collider->getCollider()->getTag() == "wall") {
        active = false;
    }
    if(collider->getCollider()->getTag() == "power") {
        trail->setMaxLength(trail->getMaxLength() + 0.2);
    }
    if(collider->getCollider()->getTag() == "speed") {
        speed += 0.001;
    }
}

