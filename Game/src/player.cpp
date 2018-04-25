#include <player.h>
#include <timer.h>
#include <textureLoader.h>
#include <iostream>


timer *T = new timer();

textureLoader tloader;


player::player()
{
    //ctor
    /*
    verticies[0].x = 0.0;verticies[0].y = 0.0;verticies[0].z = -1.0;
    verticies[1].x = 1.0;verticies[1].y = 0.0;verticies[1].z = -1.0;
    verticies[2].x = 1.0;verticies[2].y = 1.0;verticies[2].z = -1.0;
    verticies[3].x = 0.0;verticies[3].y = 1.0;verticies[3].z = -1.0;
    */

    verticies[0].x = -0.5;verticies[0].y = -0.5;verticies[0].z = -1.0;
    verticies[1].x = 0.5;verticies[1].y = -0.5;verticies[1].z = -1.0;
    verticies[2].x = 0.5;verticies[2].y = 0.5;verticies[2].z = -1.0;
    verticies[3].x = -0.5;verticies[3].y = 0.5;verticies[3].z = -1.0;

    runspeed  =0;
    jumpspeed =0;
    actionTrigger =0;


}

player::~player()
{
    //dtor
}

void player::setDirection(int d)
{
    if(dir == 0 && d == 2 || dir == 1 && d == 3 || d == 0 && dir == 2 || d == 1 && dir == 3 || dir == d) {

    }
    else {
        dir = d;
        rot = 90*dir;
        trail.addPoint();
    }
}

void player::movePlayer()
{
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

    collider->setPosition(Xpos - 0.5,Ypos + 0.5);

}



void player::drawPlayer()
{
    if(T->getTicks()>10){
        movePlayer();
        T->reset();

    trail.updateEnds(Xpos,Ypos);
    }
    glPushMatrix();

        trail.drawTrail();
    glPopMatrix();

  //  glColor3f(1.0,0.0,0.0);
   // glPushMatrix();
    glPushMatrix();


    glTranslated(Xpos,Ypos,0.0);
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



 //   glPopMatrix();


}

void player::playerInit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    T->start();

    tloader.bindTexture("images/bike.png");

    trail.init(Xpos, Ypos);

}

void player::actions(int action)
{
   switch(action){
   case 0:
       glPushMatrix();
       glTranslated(1.0,0.0,0.0);
       tloader.binder();
      //  glutSolidTeapot(1.5);
       drawPlayer();
       glPopMatrix();
       break;

   /*case 1:
       glPushMatrix();
       glTranslated(1.0,0.0,0.0);

       if(T->getTicks()>15){

        runspeed++;
        runspeed = runspeed %10;
        T->reset();
       }

       runText[runspeed].binder();
       drawPlayer();

       glPopMatrix();
       break;*/
   }

}
