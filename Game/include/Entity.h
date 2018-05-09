#ifndef ENTITY_H
#define ENTITY_H

#include "Model.h"
#include "BoxCollider.h"

class ObjectHandler;

class Entity : public Model
{
    public:
        Entity();
        virtual ~Entity();

        bool active = true;

        BoxCollider* getCollider() {return collider;}
        virtual void onCollision(ObjectHandler*, Entity* collider) = 0;

        virtual void init() = 0;

        virtual void update(ObjectHandler*) = 0;
        virtual void draw(double) = 0;

    protected:
        BoxCollider* collider = new BoxCollider(1.0f, 1.0f, "entity");

    private:


};

#endif // ENTITY_H
