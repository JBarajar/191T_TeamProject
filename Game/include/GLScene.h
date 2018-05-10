#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>

#include<gl/gl.h>
#include<iostream>
#include<vector>
#include <time.h>

class Model;

using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        virtual GLint initGL();
        virtual GLint run();
        virtual GLint drawGLScene();
        virtual GLvoid resizeGLScene(GLsizei, GLsizei);

        void resetLevel();

        virtual int windMsg(HWND,UINT, WPARAM,LPARAM);

        bool paused = false;


        WPARAM wParam;
        float screenHeight;
        float screenWidth;
    protected:

    private:
        clock_t newTime, oldTime;
        double deltaTime;


};

#endif // GLSCENE_H
