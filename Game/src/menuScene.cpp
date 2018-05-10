#include "menuScene.h"
#include "SceneHandler.h"
#include "Inputs.h"

Model *menuPlay = new Model();
Model *menuCredits = new Model();
Model *menuQuit = new Model();
parallax *plax = new parallax();
Inputs *KbIp = new Inputs();

menuScene::menuScene()
{
    //ctor
    play = 1;
    credits = 2;
    quit = 3;
    selection = play;

    //shandler->curScene = shandler-> mmScene;

    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
    menuPlay->Xpos = 0.0;
    menuPlay->Ypos = 0.0;
    menuCredits->Xpos = 0.0;
    menuCredits->Ypos = -0.25;
    menuQuit->Xpos = 0.0;
    menuQuit->Ypos = -0.5;
    menuPlay->width = 0.6;
    menuPlay->height = 0.2;
    menuCredits->width = 0.6;
    menuCredits->height = 0.2;
    menuQuit->width = 0.6;
    menuQuit->height = 0.2;
}

menuScene::~menuScene()
{
    //dtor
}

GLint menuScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    //GLLight SetLight(GL_LIGHT0);
    //GLLight Light(GL_LIGHT0);

    plax->parallaxInit("images/grid.png");
    menuPlay -> modelInit("images/button.png",true);
    menuCredits -> modelInit("images/button.png",false);
    menuQuit -> modelInit("images/button.png",false);

    return true;
}

GLint menuScene::run()
{
    drawGLScene();
}

GLint menuScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();								// Reset The Current Modelview Matrix

    gluLookAt(0,0,1,0.0,0.0,0.0,0.0,1.0,0.0);


    glPushMatrix();
        glScaled(3.33,3.33,1.0);
        plax->drawSquare(screenWidth,screenHeight);
    glPopMatrix();
    plax->scroll(true,"down",0.0005);

    glPushMatrix();
        menuPlay->drawModel();
    glPopMatrix();

    glPushMatrix();
        menuCredits->drawModel();
    glPopMatrix();

    glPushMatrix();
        menuQuit->drawModel();
    glPopMatrix();


    glScaled(1.0,1.0,1.0);

    glEnd();

}

int menuScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{
	    case WM_KEYDOWN:
          KbIp->wParam = wParam;
          KbIp->keyPressed(this);
	    break;
  }
}

void menuScene::moveSelectionUP()
{
    if (selection == quit)
    {
        selection = credits;
    }
    else if (selection == credits)
    {
        selection = play;
    }
}

void menuScene::moveSelectionDown()
{
    if (selection == play)
    {
        selection = credits;
    }
    else if (selection == credits)
    {
        selection = quit;
    }
}
void menuScene::processSelection()
{
    if (selection == play)
    {
        shandler->curScene = shandler-> gmScene;
        shandler->curScene->initGL();
    }
    else if (selection == credits)
    {
        shandler->curScene = shandler-> cdScene;
        shandler->curScene->initGL();
    }
    else if (selection == quit)
    {
          exit(0);
    }
}
