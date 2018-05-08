#ifndef BIKE_H
#define BIKE_H

#include "trail.h"
#include "timer.h"
#include "Entity.h"
#include "textureLoader.h"

class Bike : public Entity
{
    public:
        Bike();
        virtual ~Bike();

        vec verticies[4];

        float speed = 0.05;
        int dir = 0;
        float rot = 0;

        void init();
        void setDirection(int);
        void moveBike();

        virtual void draw(double dt);
        virtual void update(ObjectHandler* handler);

        virtual void onCollision(ObjectHandler* handler, Entity* collider);

        Trail* trail = new Trail();

    protected:

    private:
        char image[1024] = "images/bike.png";
        textureLoader tloader;

        float width = 0.4;
        float height = 0.4;

};

#endif // BIKE_H
