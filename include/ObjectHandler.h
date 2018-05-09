#ifndef COLLISION_H
#define COLLISION_H

#include<vector>

class BoxCollider;
class Entity;

class Trail;
class ObjectHandler
{
    public:
        ObjectHandler();
        virtual ~ObjectHandler();

        bool collisionCheck(Entity*, Entity*);
        bool trailCollisionCheck(Entity*, Trail*);

        void addEntity(Entity*);
        void removeEntity(Entity*);

        void update();
        void draw(double dt);

    protected:

    private:
        std::vector<Entity*> entities;
};

#endif // COLLISION_H
