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

        float speed = 0.006;
        int dir = 0;
        float rot = 0;

        virtual void init();
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

        float width = 0.08;
        float height = 0.08;

};

#endif // BIKE_H
