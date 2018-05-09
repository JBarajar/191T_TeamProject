#include "ObjectHandler.h"
#include "BoxCollider.h"
#include "Entity.h"
#include <iostream>
#include "Trail.h"
#include "player.h"
#include "randAI.h"
#include "PowerUp.h"

ObjectHandler::ObjectHandler()
{

}

ObjectHandler::~ObjectHandler()
{
    //dtor
}

bool ObjectHandler::collisionCheck(Entity* e1, Entity* e2)
{
    BoxCollider* a = e1->getCollider();
    BoxCollider* b = e2->getCollider();

    float l1 = a->getLeft();
    float r1 = a->getRight();
    float t1 = a->getTop();
    float b1 = a->getBot();

    float l2 = b->getLeft();
    float r2 = b->getRight();
    float t2 = b->getTop();
    float b2 = b->getBot();



    if(l1 > r2 || r1 < l2 || b1 > t2 || t1 < b2) {
        return false;
    }
    else {
        return true;
    }
}

bool ObjectHandler::trailCollisionCheck(Entity* e, Trail* t)
{
    std::vector<Point> points = t->getPoints();
    Point p1, p2;

    BoxCollider* a = e->getCollider();

    for(int i = 0; i < points.size() - 1; i++) {
        p1 = points.at(i);
        p2 = points.at(i+1);

        if(p1.x == p2.x) {
            if(p1.x >= a->getLeft() && p1.x <= a->getRight()) {
                if(p1.y - p2.y >= 0) {
                    if(a->getY() < p1.y && a->getY() > p2.y) {
                        //std::cout << "collision" << std::endl;
                        return true;
                    }
                }
                else {
                    if(a->getY() > p1.y && a->getY() < p2.y) {
                        //std::cout << "collision" << std::endl;
                        return true;
                    }
                }

            }
        }
        else if(p1.y == p2.y) {
            if(p1.y > a->getBot() && p1.y < a->getTop()) {
                if(p1.x - p2.x >= 0) {
                    if(a->getX() < p1.x && a->getX() > p2.x) {
                        //std::cout << "collision" << std::endl;
                        return true;

                    }
                }
                else {
                    if(a->getX() > p1.x && a->getX() < p2.x) {
                        //std::cout << "collision" << std::endl;
                        return true;

                    }
                }
            }
        }
        else std::cout << "points off" << std::endl;

    }
    return false;
}


void ObjectHandler::addEntity(Entity* e)
{
    entities.push_back(e);
    e->init();
}

void ObjectHandler::removeEntity(Entity* e)
{
    std::vector<Entity*>::iterator it = entities.begin();
    for(it = entities.begin(); it != entities.end(); it++) {

        if(*it == e) {
                std::cout << "removed entity" << std::endl;
            entities.erase(it);
            return;
        }
    }



}

void ObjectHandler::update()
{
    //update entities
    for(int i = 0; i < entities.size(); i++) {
        if(entities.at(i)->active) entities.at(i)->update(this);
    }

    //check collision between entities
    for(int i = 0; i < entities.size(); i++) {
        if(!entities.at(i)->active) continue;
        for(int j = i+1; j < entities.size(); j++) {
            if(!entities.at(j)->active) continue;
            if(collisionCheck(entities.at(i), entities.at(j))) {
                entities.at(i)->onCollision(this, entities.at(j));
                entities.at(j)->onCollision(this, entities.at(i));
            }
        }
    }

    //check collisions between entities and trails
    for(int i = 0; i < entities.size(); i++) {
        if(!entities.at(i)->active) continue;
        for(int j = 0; j < entities.size(); j++) {
            if(!entities.at(j)->active) continue;
            if(dynamic_cast<Bike*>(entities.at(j))) {
                if(trailCollisionCheck(entities.at(i), (dynamic_cast<Bike*>(entities.at(j)))->trail)) {
                    entities.at(i)->active = false;
                }
            }
        }
    }
}

void ObjectHandler::draw(double dt)
{
    //draw all entities
    for(int i = 0; i < entities.size(); i++) {
        glPushMatrix();
            if(entities.at(i)->active) entities.at(i)->draw(dt);
        glPopMatrix();
    }
}


