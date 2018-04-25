#include "randAI.h"

randAI::randAI()
{
    //ctor
    verticies[0].x = -0.5; verticies[0].y = -0.5; verticies[0].z = -1.0;
    verticies[1].x =  0.5; verticies[1].y = -0.5; verticies[1].z = -1.0;
    verticies[2].x =  0.5; verticies[2].y =  0.5; verticies[2].z = -1.0;
    verticies[3].x = -0.5; verticies[3].y =  0.5; verticies[3].z = -1.0;
}

randAI::~randAI()
{
    //dtor
}

void randAI::rAIInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T->start();                                         //Start step timer
    A->start();                                         //Start action timer
    tloader.bindTexture("images/bike.png");             //Bind bike image
    rAITrail.init(Xpos, Ypos);                          //Initialize light trail
}

void randAI::setDirection(int d)
{
    //Prevents bike from doing 180 turns
    if(dir == 0 && d == 2 || dir == 1 && d == 3 || d == 0 && dir == 2 || d == 1 && dir == 3 || dir == d) {
        //Do nothing
    }
    else {
        dir = d;            //Set new direction
        rAITrail.addPoint();
    }
}

void randAI::drawRAI()
{
    //Move after every step
    if(T->getTicks()>10){
        moveRAI();
        rAITrail.updateEnds(Xpos,Ypos);
        T->reset();
        if(A->getTicks()>150){
            actions();
            A->reset();
        }
    }

    //Draw trail behind RAI
    glPushMatrix();
        rAITrail.drawTrail();
    glPopMatrix();

    //Draw bike
    glPushMatrix();
        glTranslated(Xpos,Ypos,0.0);
        //Converts dir from int to degree
        glRotated(dir * 90, 0,0,1);
        tloader.binder();
        glScaled(0.1,0.1,1);

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

    glPopMatrix();
}

void randAI::actions()
{

    int rDir  = rand()%100;         //Random direction
    int NDist = 3;  //anyTrail.dist(North);
    int EDist = 3;  //anyTrail.dist(East);
    int WDist = 3;  //anyTrail.dist(West);

    //Gets dir for left turn
    int lTurn = dir - 1;
    if (lTurn == -1)
        lTurn = 3;

    //Gets dir for right turn
    int rTurn = dir + 1;
    if (rTurn == 4)
        rTurn = 0;

    //Case: No near trails/walls
    if((NDist > 2) && (EDist > 2) && (WDist > 2)){
        //70% chance to continue in same direction
        if(rDir < 70)
            ;//Do nothing
        //15% chance to turn left
        else if(rDir >= 85)
            setDirection(lTurn);
        //15% chance to turn right
        else
            setDirection(rTurn);
    }

}

void randAI::moveRAI()
{
    //Move RAI in the direction its facing
    switch(dir) {
    case 0:
        Ypos += speed;
        break;
    case 1:
        Xpos -= speed;
        break;
    case 2:
        Ypos -= speed;
        break;
    case 3:
        Xpos += speed;
        break;
    }
}
