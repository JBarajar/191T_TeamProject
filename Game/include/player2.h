#ifndef PLAYER2_H
#define PLAYER2_H

#include<Entity.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include<Trail.h>
#include<BoxCollider.h>
#include <timer.h>
#include "Bike.h"

class player2 : public Bike
{
    public:
        player2();
        virtual ~player2();

        virtual void update(ObjectHandler* handler);

    protected:

    private:
};

#endif // PLAYER2_H
