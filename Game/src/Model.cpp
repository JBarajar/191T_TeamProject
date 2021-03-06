#include "Model.h"


Model::Model()
{
    //ctor


        tex = new textureLoader();
        RotateX =0.0; // Rotations
        RotateY =0.0;
        RotateZ =0.0;

        Zoom = 0.0;  //translations
        Xpos = 0.0;
        Ypos = 0.0;

        verticies[0].x=-width/2;verticies[0].y=-height/2;verticies[0].z=-1.0;
        verticies[1].x=width/2;verticies[1].y=-height/2;verticies[1].z=-1.0;
        verticies[2].x=width/2;verticies[2].y=height/2;verticies[2].z=-1.0;
        verticies[3].x=-width/2;verticies[3].y=height/2;verticies[3].z=-1.0;
}

Model::~Model()
{
    //dtor
}
void Model::modelInit(char *fileName, bool trans)
{
   if(trans)
   {
     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   }

    tex->binder();
    tex->bindTexture(fileName);
}

void Model::drawModel()
{
    verticies[0].x=-width/2;verticies[0].y=-height/2;verticies[0].z=-1.0;
    verticies[1].x=width/2;verticies[1].y=-height/2;verticies[1].z=-1.0;
    verticies[2].x=width/2;verticies[2].y=height/2;verticies[2].z=-1.0;
    verticies[3].x=-width/2;verticies[3].y=height/2;verticies[3].z=-1.0;

    tex->binder();
    glTranslated(Xpos,Ypos,0);
    glRotated(RotateX,1,0,0);
    glRotated(RotateY,0,1,0);
    glRotated(RotateZ,0,0,1);

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

    tex->nullTex();


  //  glutSolidTeapot(1.5);
}
