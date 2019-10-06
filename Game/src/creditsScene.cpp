#include "creditsScene.h"
#include "SceneHandler.h"
#include "Inputs.h"
#include "sounds.h"

parallax *pllx = new parallax();
Inputs *KbInp = new Inputs();
sounds *soud = new sounds();
Model *joey = new Model();
Model *zach = new Model();
Model *daniel = new Model();
Model *juan = new Model();
Model *team = new Model();
Model *controls = new Model();
Model *p1 = new Model();
Model *p2 = new Model();

creditsScene::creditsScene()
{
    //ctor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    zach->Xpos = 0.5;
    zach->Ypos = 0.20; //.25
    joey->Xpos = 0.5;
    joey->Ypos = 0.0;//.50
    daniel->Xpos = 0.50;
    daniel->Ypos = -0.20;// .75
    zach->width = 0.6;
    zach->height = 0.2;
    joey->width = 0.6;
    joey->height = 0.2;
    daniel->width = 0.6;
    daniel->height = 0.2;
    juan->width = 0.6;
    juan->height = 0.2;
    juan->Ypos = -.40; //0
    juan->Xpos = 0.50;

    team->Xpos = 0.50;
    team->Ypos = 0.50;
    team->width = .7;
    team->height = .3;

    controls->Xpos = -.5;
    controls->Ypos = .5;
    controls->width = .7;
    controls->height = .3;

    p1->Xpos = -.5;
    p1->Ypos = .20;
    p1->width = .6;
    p1->height = .2;

    p2->Xpos = -.5;
    p2->Ypos = .0;
    p2->width = .6;
    p2->height = .2;



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
    controls->modelInit("images/controls.png", false);
    p1->modelInit("images/p1c.png", false);
    p2->modelInit("images/p2c.png", false);
    team->modelInit("images/team.png", false);
    zach->modelInit("images/zach.png", true);
    joey->modelInit("images/joey.png",false);
    daniel->modelInit("images/daniel.png",false);
    juan->modelInit("images/juan.png",false);
    pllx->parallaxInit("images/gridclean.png");
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
    glPushMatrix();
        zach->drawModel();
    glPopMatrix();

    glPushMatrix();
        joey->drawModel();
    glPopMatrix();

    glPushMatrix();
        juan->drawModel();
    glPopMatrix();

    glPushMatrix();
        daniel->drawModel();
    glPopMatrix();

    glPushMatrix();
        team->drawModel();
    glPopMatrix();

    glPushMatrix();
        controls->drawModel();
    glPopMatrix();

    glPushMatrix();
        p1->drawModel();
    glPopMatrix();

    glPushMatrix();
        p2->drawModel();
    glPopMatrix();

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
