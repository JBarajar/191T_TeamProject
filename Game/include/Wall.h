#ifndef WALL_H
#define WALL_H

#include "Entity.h"
#include "textureLoader.h"

class Wall : public Entity
{
    public:
        Wall(float w, float h);
        virtual ~Wall();

        vec verticies[4];

        bool active = true;

        virtual void onCollision(ObjectHandler*, Entity*);

        virtual void init();

        virtual void update(ObjectHandler*);
        virtual void draw(double);

    protected:

    private:
        float width;
        float height;
        textureLoader tloader;
        char image[1024] = "images/bike.png";
};

#endif // WALL_H
