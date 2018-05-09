#ifndef RANDAI_H
#define RANDAI_H

#include<Model.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include<Trail.h>
#include <timer.h>
#include <Entity.h>
#include <vector>
#include "ObjectHandler.h"
#include "Bike.h"

/*
    This AI will move randomnly favoring its current direction over turning.
    It will look 2 positions in move directions to help with decision making.
*/

typedef struct
{
    float x;
    float y;
    float z;
}AIvec;

class randAI : public Bike
{
    public:
        randAI();
        virtual ~randAI();

        timer *A = new timer();     //Action timer
        textureLoader tloader;      //Loads bike image

        virtual void update(ObjectHandler* handler);

        void updateColliders(vector<BoxCollider>* col);
        void setDistances();
        void actions();          //Decide next action

        virtual void onCollision(Entity* collider);

    protected:

    private:
        int NDist = 0;  //anyTrail.dist(North);
        int EDist = 0;  //anyTrail.dist(East);
        int WDist = 0;  //anyTrail.dist(West);

        BoxCollider* nCol = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* eCol = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* sCol = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* wCol = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* nCol2 = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* eCol2 = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* sCol2 = new BoxCollider(1.0f, 1.0f, "probe");
        BoxCollider* wCol2 = new BoxCollider(1.0f, 1.0f, "probe");

        vector<BoxCollider> *cols = new vector<BoxCollider>;
        cols->push_back(nCol); cols->push_back(wCol); cols->push_back(sCol); cols->push_back(eCol);
        vector<BoxCollider> *cols2 = new vector<BoxCollider>;
        cols2->push_back(nCol2); cols2->push_back(wCol2); cols2->push_back(sCol2); cols2->push_back(eCol2);
};

#endif // RANDAI_H
