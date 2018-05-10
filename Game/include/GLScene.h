#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>

#include<gl/gl.h>
#include<iostream>
#include<vector>
#include <time.h>
#include <timer.h>

class Model;

using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        GLint initGL();
        GLint run();
        GLint drawGLScene();
        GLvoid resizeGLScene(GLsizei, GLsizei);

        void resetLevel();

        int windMsg(HWND,UINT, WPARAM,LPARAM);

        bool paused = false;


        WPARAM wParam;
        float screenHeight;
        float screenWidth;

        bool p1win = false;
        bool p2win = false;
        bool draw = false;
        bool finalwin = false;

        int lvl;

        int scores[2];
    protected:

    private:
        clock_t newTime, oldTime;
        double deltaTime;
        timer ttime;


};

#endif // GLSCENE_H
