#ifndef MODEL_H
#define MODEL_H

#include<windows.h>
#include<GL/glut.h>
#include <textureLoader.h>

typedef struct{
 float x;
 float y;
 float z;
}vec1;

class Model
{

    public:
        Model();
        virtual ~Model();
        void drawModel();
        void modelInit(char *,bool);

        double RotateX;
        double RotateY;
        double RotateZ;

        double Zoom;
        double Xpos;
        double Ypos;
        double lastYpos;
        double lastXpos;

        vec1 verticies[4];

        float width = 0.4;
        float height = 0.4;
        textureLoader *tex ;//= new textureLoader();


    protected:

    private:

};

#endif // MODEL_H
