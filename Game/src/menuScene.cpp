#include "menuScene.h"
#include "SceneHandler.h"
#include "Inputs.h"
#include "sounds.h"

Model *menuPlay = new Model();
Model *menuCredits = new Model();
Model *menuQuit = new Model();
Model *title = new Model();
parallax *plax = new parallax();
Inputs *KbIp = new Inputs();
sounds *sds = new sounds();

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
    title->Xpos = 0.0;
    title->Ypos = 0.40;
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
    title->width = 0.7;
    title->height = 0.4;


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
    title->modelInit("images/t1.png", false);
    plax->parallaxInit("images/gridclean.png");
    menuPlay -> modelInit("images/buttonPlay.png",true);
    menuCredits -> modelInit("images/buttonCred.png",false);
    menuQuit -> modelInit("images/buttonQuit.png",false);
    //title->modelInit("images/title1.png", true);
    sds->initSounds();
    sds->playMusic("sounds/mnmu.wav");

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
        title->drawModel();
    glPopMatrix();

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
        sds->stopAllSounds();
        shandler->curScene->initGL();
    }
    else if (selection == credits)
    {
        shandler->curScene = shandler-> cdScene;
        sds->stopAllSounds();
        shandler->curScene->initGL();
    }
    else if (selection == quit)
    {
          exit(0);
    }
}
