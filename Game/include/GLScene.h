#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>

#include<gl/gl.h>
#include<iostream>
#include<vector>

class Model;

using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        GLint initGL();
        GLint drawGLScene();
        GLvoid resizeGLScene(GLsizei, GLsizei);

        int windMsg(HWND,UINT, WPARAM,LPARAM);


        WPARAM wParam;
        float screenHeight;
        float screenWidth;
    protected:

    private:
        vector<Model*> entities;

};

#endif // GLSCENE_H
