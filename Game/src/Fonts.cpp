#include "Fonts.h"
#include <textureLoader.h>

textureLoader *fTex = new textureLoader();

Fonts::Fonts()
{
    //ctor
    zoom =-4.0;
    xpos = -2.5;
    ypos =.5;
    zpos =0.0;
    cCnt =0;
}

Fonts::~Fonts()
{
    //dtor
}

void Fonts::initFonts(char* fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    fTex->binder();
    fTex->bindTexture(fileName);
}

void Fonts::buildFont(char* str)
{
    for(int i=0;i<strlen(str);i++)
    {
        switch (str[i]){
        case 'A':
              C[cCnt].xmin = 0.002;
              C[cCnt].xmax = 1.0/9.0 - 0.02;
              C[cCnt].ymin = 1.0/9.0 - 0.02;//6.0/7.0;
              C[cCnt].ymax = 0.002;//1.0/7.0;

        break;

        case 'B':
              C[cCnt].xmin = (1.0/9.0);
              C[cCnt].xmax = 2.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;

        case 'C':
              C[cCnt].xmin = (2.0/9.0);
              C[cCnt].xmax = 3.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'D':
              C[cCnt].xmin = (3.0/9.0);
              C[cCnt].xmax = 4.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'E':
              C[cCnt].xmin = (4.0/9.0);
              C[cCnt].xmax = 5.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'F':
              C[cCnt].xmin = (5.0/9.0);
              C[cCnt].xmax = 6.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'G':
              C[cCnt].xmin = (6.0/9.0);
              C[cCnt].xmax = 7.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'H':
              C[cCnt].xmin = (7.0/9.0);
              C[cCnt].xmax = 8.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'I':
              C[cCnt].xmin = (8.0/9.0);
              C[cCnt].xmax = 9.0/9.0;
              C[cCnt].ymin = 1.0/10.0; //
              C[cCnt].ymax = 0.001;//+(1/9);
            break;
        case 'J':
              C[cCnt].xmin = 0.035;
              C[cCnt].xmax = 1.0/10.0;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;

        case 'K':
              C[cCnt].xmin = 1.0/9.0;
              C[cCnt].xmax = 2.0/10.0;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'L':
              C[cCnt].xmin = 2.0/9.0;
              C[cCnt].xmax = 3.0/10.0 + 0.002;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'M':
              C[cCnt].xmin = 3.0/9.0;
              C[cCnt].xmax = 4.0/10.0 + .04;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'N':
              C[cCnt].xmin = 4.0/9.0 - 0.02;
              C[cCnt].xmax = 5.0/10.0 + .04;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'O':
              C[cCnt].xmin = 5.0/9.0 - 0.02 ;
              C[cCnt].xmax = 6.0/10.0 + 0.05;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'P':
              C[cCnt].xmin = 6.0/9.0  ;
              C[cCnt].xmax = 7.0/10.0 + 0.05;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'Q':
              C[cCnt].xmin = 7.0/9.0 - 0.015 ;
              C[cCnt].xmax = 8.0/10.0 + 0.07;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'R':
              C[cCnt].xmin = 8.0/9.0 -0.012 ;
              C[cCnt].xmax = 9.0/10.0 + 0.07;
              C[cCnt].ymin = 2.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 1.0/10.0;//1.0/7.0;
        break;
        case 'S':
              C[cCnt].xmin = 0.025;
              C[cCnt].xmax = 1.0/10.0 + 0.0 ;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'T':
              C[cCnt].xmin = 1.0/9.0;
              C[cCnt].xmax = 2.0/10.0 + 0.0 ;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'U':
              C[cCnt].xmin = 2.0/9.0 - 0.01;
              C[cCnt].xmax = 3.0/10.0 + 0.03;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'V':
              C[cCnt].xmin = 3.0/9.0 - 0.01;
              C[cCnt].xmax = 4.0/10.0 + 0.03;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'W':
              C[cCnt].xmin = 4.0/9.0 - 0.01;
              C[cCnt].xmax = 5.0/10.0 + 0.04;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'X':
              C[cCnt].xmin = 5.0/9.0 - 0.01;
              C[cCnt].xmax = 6.0/10.0 + 0.04;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'Y':
              C[cCnt].xmin = 6.0/9.0 + 0.005;
              C[cCnt].xmax = 7.0/10.0 + 0.04;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case 'Z':
              C[cCnt].xmin = 7.0/9.0 - 0.01;
              C[cCnt].xmax = 8.0/10.0 + 0.06;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        case '0':
              C[cCnt].xmin = 7.0/9.0 - 0.01;
              C[cCnt].xmax = 8.0/10.0 + 0.06;
              C[cCnt].ymin = 3.0/10.0;//6.0/7.0;
              C[cCnt].ymax = 2.0/10.0;//1.0/7.0;
        break;
        }

        cCnt++;
    }
}

void Fonts::drawFont(int i)
{
    fTex->binder();

    glPushMatrix();
    glBegin(GL_QUADS);
    //glBeg
    //bottom left

    glTexCoord2f(C[i].xmin,C[i].ymin);   // fix your y vales
    glVertex3f(-0.1,-0.1,0);
    //bottom right
    glTexCoord2f(C[i].xmax,C[i].ymin);
    glVertex3f(0.1,-0.1,0);
    //top right
    glTexCoord2f(C[i].xmax,C[i].ymax);
    glVertex3f(0.1,0.1,0);
    //top left
    glTexCoord2f(C[i].xmin,C[i].ymax);
    glVertex3f(-0.1,0.1,0);
   // glTranslatef(20,2,2);
    glEnd();
    glPopMatrix();

}
