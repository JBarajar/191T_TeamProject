#ifndef PLAYER_H
#define PLAYER_H

#include<Entity.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include<Trail.h>
#include<BoxCollider.h>
#include <timer.h>
#include "Bike.h"


class player : public Bike
{
    public:
        player();
        virtual ~player();

        virtual void update(ObjectHandler* handler);

    protected:

    private:

};

#endif // PLAYER_H
