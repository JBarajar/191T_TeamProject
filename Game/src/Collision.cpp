#include "Collision.h"
#include "BoxCollider.h"

Collision::Collision()
{
    //ctor
}

Collision::~Collision()
{
    //dtor
}

bool Collision::collisionCheck(BoxCollider* a, BoxCollider* b)
{
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
    else return true;
}
