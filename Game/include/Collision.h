#ifndef COLLISION_H
#define COLLISION_H

class BoxCollider;

class Collision
{
    public:
        Collision();
        virtual ~Collision();

        bool collisionCheck(BoxCollider*, BoxCollider*);

    protected:

    private:
};

#endif // COLLISION_H
