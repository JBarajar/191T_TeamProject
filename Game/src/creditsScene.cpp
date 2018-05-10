#include "creditsScene.h"
#include "SceneHandler.h"
#include "Inputs.h"
#include "sounds.h"

parallax *pllx = new parallax();
Inputs *KbInp = new Inputs();
sounds *soud = new sounds();

creditsScene::creditsScene()
{
    //ctor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

creditsScene::~creditsScene()
{
    //dtor
}

GLint creditsScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    //GLLight SetLight(GL_LIGHT0);
    //GLLight Light(GL_LIGHT0);

    pllx->parallaxInit("images/grid.png");
    soud->initSounds();
    soud->playMusic("sounds/mnmu.wav");

    return true;
}

GLint creditsScene::run()
{
    drawGLScene();
}

GLint creditsScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();								// Reset The Current Modelview Matrix

    gluLookAt(0,0,1,0.0,0.0,0.0,0.0,1.0,0.0);


    glPushMatrix();
        glScaled(3.33,3.33,1.0);
        pllx->drawSquare(screenWidth,screenHeight);
    glPopMatrix();
    pllx->scroll(true,"right",0.0005);

    glScaled(1.0,1.0,1.0);

    glEnd();

}

int creditsScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{
	    case WM_KEYDOWN:
          KbInp->wParam = wParam;
          KbInp->keyPressed(this);
	    break;
  }
}

void creditsScene::processSelection()
{
  shandler->curScene = shandler-> mmScene;
  soud->stopAllSounds();
  shandler->curScene->initGL();
}
