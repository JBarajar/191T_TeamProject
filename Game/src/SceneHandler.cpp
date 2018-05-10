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
    gameCredits = 2;
    gameOver = 3;
    pauseGame = 4;

    stateChange = false;
    curState  = mainMenu;
    prevState = mainMenu;
    curScene = mmScene;
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

void SceneHandler::run()
{
    curScene->run();
}

void SceneHandler::reset()
{
    curState  = mainMenu;
    prevState = mainMenu;
}
