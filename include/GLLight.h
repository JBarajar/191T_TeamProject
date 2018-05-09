#ifndef GLLIGHT_H
#define GLLIGHT_H
#include<GLScene.h>

class GLLight:GLScene
{
    public:
        GLLight(GLenum Light);
        virtual ~GLLight();

        GLfloat light_ambient[4]  = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat light_diffuse[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat light_position[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

        GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat high_shininess[1] = { 100.0f };

        GLvoid SetLight(GLenum);

    protected:

    private:
};

#endif // GLLIGHT_H
