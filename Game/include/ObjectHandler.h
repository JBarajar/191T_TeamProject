#ifndef COLLISION_H
#define COLLISION_H

#include<vector>

class player;
class player2;

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
        void clearObjects();

        void update();
        void draw(double dt);

        void loadLevel1(player**, player2**);
        void loadLevel2(player**, player2**);

    protected:

    private:
        std::vector<Entity*> entities;
};

#endif // COLLISION_H
