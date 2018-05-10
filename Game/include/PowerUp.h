#ifndef POWERUP_H
#define POWERUP_H

#include <Entity.h>
#include <textureLoader.h>


class PowerUp : public Entity
{
    public:
        PowerUp();
        virtual ~PowerUp();

        vec verticies[4];

        virtual void onCollision(ObjectHandler*, Entity*);

        virtual void init();

        virtual void update(ObjectHandler*);
        virtual void draw(double);

    protected:
        char* image = "images/Wall.png";
    private:

        float width = 0.04;
        float height = 0.04;
        textureLoader tloader;

};

#endif // POWERUP_H
