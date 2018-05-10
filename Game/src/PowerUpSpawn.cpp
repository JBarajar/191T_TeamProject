#include "PowerUpSpawn.h"
#include <stdlib.h>
#include <ObjectHandler.h>
#include <iostream>
#include <time.h>
#include <stdio.h>

PowerUpSpawn::PowerUpSpawn(float x, float y)
{
    //ctor
    Xpos = x;
    Ypos = y;

    collider->setHeight(height);
    collider->setWidth(width);
}

PowerUpSpawn::~PowerUpSpawn()
{
    //dtor
}

void PowerUpSpawn::spawnItem(ObjectHandler* handler)
{
    int item = rand() % 2;
    //std::cout << "spawn item" << std::endl;

    if(item == 0) {
        handler->addEntity(new Power(Xpos, Ypos));
    }
    else if(item == 1) {
        handler->addEntity(new SpeedUp(Xpos,Ypos));
    }
}

void PowerUpSpawn::init()
{
    collider->setPosition(Xpos,Ypos);
    sTime = rand() % sTimeLimit + 3000;
    std::cout << sTime << std::endl;
    spawnTimer.start();
}


void PowerUpSpawn::onCollision(ObjectHandler* handler, Entity* collider)
{
    if(collider->getCollider()->getTag() == "bike") {
        if(!canSpawn) {
            canSpawn = true;
            sTime = rand() % sTimeLimit + 3000;
            spawnTimer.reset();
            //std::cout << "reset" << std::endl;
        }
    }
}


void PowerUpSpawn::update(ObjectHandler* handler)
{
    //std::cout << canSpawn << std::endl;
    if(canSpawn) {
        //std::cout << spawnTimer.getTicks() << " " << sTime << std::endl;
        if(spawnTimer.getTicks() >= sTime) {
            canSpawn = false;
            spawnItem(handler);
        }
    }
}

void PowerUpSpawn::draw(double)
{

}

