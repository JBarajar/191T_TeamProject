#ifndef POWERUP_H
#define POWERUP_H

#include <Entity.h>
#include <textureLoader.h>


class PowerUp : public Entity
{
    public:
        PowerUp(float x, float y);
        virtual ~PowerUp();

        vec verticies[4];

        virtual void onCollision(ObjectHandler*, Entity*);

        virtual void init();

        virtual void update(ObjectHandler*);
        virtual void draw(double);

    protected:

    private:

        float width = 0.04;
        float height = 0.04;
        textureLoader tloader;
        char image[1024] = "images/wall.png";
};

#endif // POWERUP_H
