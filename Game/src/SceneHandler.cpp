#include "SceneHandler.h"
SceneHandler::SceneHandler()
{
    //font = new Font();

    play = 1;
    credits = 2;
    quit = 3;
    selection = play;

    mainMenu = 0;
    playGame = 1;
    pauseGame = 2;
    gameOver = 3;

    stateChange = false;
    curState  = mainMenu;
    prevState = mainMenu;
}

SceneHandler::~SceneHandler()
{
    //dtor
}

void SceneHandler::init(float screenWidth, float screenHeight)
{

}

void SceneHandler::moveSelectionUP()
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

void SceneHandler::moveSelectionDown()
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

void SceneHandler::setPaused()
{

    if (curState == pauseGame)
    {
        curState = prevState;
    }
    else
    {
        prevState = curState;
        curState = pauseGame;
    }
}

void SceneHandler::processSelection()
{
    if (curState == mainMenu)
    {
        if (selection == play)
        {
            curState = playGame;

            stateChange = true;
        }
        else if (selection == credits)
        {

        }
        else if (selection == quit)
        {

            exit(0);
        }
    }
    else if (curState == gameOver)
    {
        curState = mainMenu;

        stateChange = true;
    }
    else if (curState = pauseGame)
    {
        if (selection == play)
        {
            setPaused();
        }
        else if(selection == quit)
        {
            curState = mainMenu;

            stateChange = true;
        }
    }

}

void SceneHandler::drawMainMenu()
{

}

void SceneHandler::draw()
{
   /*if (gameStateCurrent == gameOver)
    {
        font->drawFont("finish", 0.0f, 0.4f, 0.5f, true, true);
        font->drawFont("loading...", 0.0f, 0.0f, 0.1f, true, true);
    }
    else if (gameStateCurrent == pauseGame)
    {
        drawMainMenu();
        // draw menu text
        font->drawFont("resume", startBar.position.x, startBar.position.y, startBar.radius.y, true, true);
        font->drawFont("main menu", quitBar.position.x, quitBar.position.y, quitBar.radius.y, true, true);
        font->drawFont("use arrow keys to select", 0.0f, -modelState.screenBounds.y + 0.35f, 0.1f, true, true);
  }
    else if (gameStateCurrent == isMenu)
    {
        drawMainMenu();

        font->drawFont("battle", 0.0f, modelState.screenBounds.y - 0.3f, 0.5f, true, true);
        font->drawFont("bikes", 0.0f, modelState.screenBounds.y - 0.8f, 0.5f, true, true);
        font->drawFont("play", startBar.position.x, startBar.position.y, startBar.radius.y, true, true);
        font->drawFont("credits", creditsBar.position.x, creditsBar.position.y, creditsBar.radius.y, true, true);
        font->drawFont("quit", quitBar.position.x, quitBar.position.y, quitBar.radius.y, true, true);

    }*/

}

void SceneHandler::reset()
{
    curState  = mainMenu;
    prevState = mainMenu;
}
