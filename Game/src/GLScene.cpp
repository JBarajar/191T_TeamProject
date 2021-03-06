#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include <Inputs.h>
#include <parallax.h>
#include <player.h>
#include <player2.h>
#include <skyBox.h>
#include <randAI.h>
#include <ObjectHandler.h>
#include <Wall.h>
#include <PowerUp.h>
#include <Power.h>
#include <SpeedUp.h>
#include <time.h>
#include <stdio.h>
#include <sounds.h>

Model *modelTeapot = new Model();
Inputs *KbMs = new Inputs();
parallax *plx = new parallax();
parallax *p1w = new parallax();
parallax *p2w = new parallax();
player *ply = new player();
player2 *ply2 = new player2();
skyBox *sky = new skyBox;
sounds *snds = new sounds();
//randAI *rai = new randAI();
//randAI *rai2 = new randAI();
ObjectHandler* handler = new ObjectHandler();

const double interval = 0.01;

GLScene::GLScene()
{
    //ctor
    screenHeight= GetSystemMetrics(SM_CYSCREEN);
    screenWidth = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

GLint GLScene::initGL()
{
    srand(time(NULL));
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0f,1.0f,1.0f,0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    GLLight SetLight(GL_LIGHT0);
    GLLight Light(GL_LIGHT0);

    ttime.start();

    //modelTeapot->modelInit("images/player/player0.png",true);
    p1w->parallaxInit("images/p1win.png");
    p2w->parallaxInit("images/p2win.png");
    plx->parallaxInit("images/gridclean.png");
    snds->initSounds();
    snds->playMusic("sounds/battle.wav");

    //ply->init();
    //rai->init();
    //sky->loadTextures();

    lvl = rand() % 3;

    switch(lvl) {
    case 0:
        handler->loadLevel1(&ply, &ply2);
        break;
    case 1:
        handler->loadLevel2(&ply, &ply2);
        break;
    case 2:
        handler->loadLevel3(&ply, &ply2);
        break;
    }

    //handler->loadLevel1(&ply, &ply2);

    /*handler->addEntity(ply);
    handler->addEntity(ply2);

    handler->addEntity(rai);
    rai2->Xpos = 0.9;
    handler->addEntity(rai2);
    handler->addEntity(new Wall(-1.25,0,0.04,1.37));
    handler->addEntity(new Wall(1.25,0,0.04,1.37));
    handler->addEntity(new Wall(0,0.7,2.54,0.04));
    handler->addEntity(new Wall(0,-0.7,2.54,0.04));
    handler->addEntity(new Power(0.0,0.0));
    handler->addEntity(new Power(0.5,0.5));
    handler->addEntity(new Power(-0.5,-0.5));
    handler->addEntity(new SpeedUp(-0.5, 0.5));
    handler->addEntity(new SpeedUp(0.5, -0.5));
    handler->addEntity(new SpeedUp(0.9, 0.0));
    handler->addEntity(new SpeedUp(-0.9, 0.0));*/

    oldTime = clock();
    newTime = clock();
    deltaTime = 0;

    return true;
}

void GLScene::resetLevel() {
    handler->clearObjects();
    handler->loadLevel1(&ply,&ply2);

}

GLint GLScene::run()
{
    newTime = clock();
    deltaTime += ((double)newTime - (double)oldTime)/CLOCKS_PER_SEC;
    oldTime = newTime;

    while(deltaTime >= interval) {
        deltaTime -= interval;

        if(!paused) handler->update();

        if(!draw && !p1win && !p2win) {
        if(!handler->entities.at(0)->active && !handler->entities.at(1)->active) {
            draw = true;
            ttime.reset();
        }
        else if(!handler->entities.at(0)->active && handler->entities.at(1)->active) {
            p2win = true;
            ttime.reset();
            scores[1]++;
        }
        else if(handler->entities.at(0)->active && !handler->entities.at(1)->active) {
            p1win = true;
            ttime.reset();
            scores[0]++;
        }
        }

    }

    drawGLScene();


}


GLint GLScene::drawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();								// Reset The Current Modelview Matrix

	gluLookAt(0,0,1,0.0,0.0,0.0,0.0,1.0,0.0);


    glPushMatrix();
        //glScaled(3.33,3.33,1.0);
        plx->drawSquare(screenWidth,screenHeight);
    glPopMatrix();
        //plx->scroll(true,"right",0.001);
/*
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glScaled(200,200,200);
        sky->drawBox();
        glEnable(GL_LIGHTING);
    glPopMatrix();
*/

    glScaled(1.0,1.0,1.0);
    /*glPushMatrix();
        ply->drawPlayer();
    glPopMatrix();

    glPushMatrix();
        rai->drawRAI();
    glPopMatrix();*/

    if(!finalwin) handler->draw(deltaTime/interval);

    if(draw) {
        if(ttime.getTicks() > 3000) {
            draw = false;
            p1win = false;
            p2win = false;

            int oldlvl = lvl;
            while(lvl == oldlvl) lvl = rand() % 3;

            switch(lvl) {
            case 0:
                handler->loadLevel1(&ply, &ply2);
                break;
            case 1:
                handler->loadLevel2(&ply, &ply2);
                break;
            case 2:
                handler->loadLevel3(&ply, &ply2);
                break;
            }

        }
    }

    if(p1win) {
    glPushMatrix();
        glScaled(0.5,0.5,1.0);
        p1w->drawSquare(400,200);

        if(ttime.getTicks() > 3000) {
            if(scores[0] >= 3) finalwin = true;

            if(!finalwin) {
            draw = false;
            p1win = false;
            p2win = false;



            int oldlvl = lvl;
            while(lvl == oldlvl) lvl = rand() % 3;

            switch(lvl) {
            case 0:
                handler->loadLevel1(&ply, &ply2);
                break;
            case 1:
                handler->loadLevel2(&ply, &ply2);
                break;
            case 2:
                handler->loadLevel3(&ply, &ply2);
                break;
            }

            }
        }
    glPopMatrix();
    }

    if(p2win) {
    glPushMatrix();
        glScaled(0.5,0.5,1.0);
        p2w->drawSquare(400,200);

        if(ttime.getTicks() > 3000) {
            if(scores[1] >= 3) finalwin = true;

            if(!finalwin) {
            draw = false;
            p1win = false;
            p2win = false;



            int oldlvl = lvl;
            while(lvl == oldlvl) lvl = rand() % 3;

            switch(lvl) {
            case 0:
                handler->loadLevel1(&ply, &ply2);
                break;
            case 1:
                handler->loadLevel2(&ply, &ply2);
                break;
            case 2:
                handler->loadLevel3(&ply, &ply2);
                break;
            }

            }

        }
    glPopMatrix();
    }



    //glEnd();

}

GLvoid GLScene::resizeGLScene(GLsizei width, GLsizei height)
{
   GLfloat aspectRatio = (GLfloat)width/(GLfloat)height;
   glViewport(0,0,width,height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective (40.0f,aspectRatio,0.1f, 100.0f);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int GLScene::windMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)									// Check For Windows Messages
	{

	    case WM_KEYDOWN:
	        KbMs->wParam = wParam;
	        KbMs->keyPressed(this);
	        if(!paused) {
	        KbMs->keyPressed(modelTeapot);
	        KbMs->keyEnv(plx, 0.005);
	        KbMs->keyPressed(ply);
	        KbMs->p2keyPressed(ply2);
	        KbMs->keyPressed(sky);
	        KbMs->keyPressed(handler);
	        }

	    break;

	    case WM_KEYUP:								// Has A Key Been Released?
		{
			KbMs->wParam = wParam;
			KbMs->keyUP();
			KbMs->keyUp(ply);
		break;								// Jump Back
		}

		case WM_LBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

   		case WM_RBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

          case WM_MBUTTONDOWN:
        {
            KbMs->wParam = wParam;
            KbMs->mouseEventDown(modelTeapot,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        {
            KbMs->mouseEventUp();
        break;								// Jump Back
        }

        case WM_MOUSEMOVE:
        {
             KbMs->mouseMove(modelTeapot, LOWORD(lParam),HIWORD(lParam));
             KbMs->mouseMove(sky,LOWORD(lParam),HIWORD(lParam));
        break;								// Jump Back
        }

        case WM_MOUSEWHEEL:
        {
            KbMs->mouseWheel(modelTeapot,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;								// Jump Back
        }
}
}
