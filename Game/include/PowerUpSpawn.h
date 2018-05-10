#ifndef POWERUPSPAWN_H
#define POWERUPSPAWN_H

#include <Entity.h>
#include <Power.h>
#include <SpeedUp.h>
#include <timer.h>


class PowerUpSpawn : public Entity
{
    public:
        PowerUpSpawn(float x, float y);
        virtual ~PowerUpSpawn();

        void spawnItem(ObjectHandler* handler);

        virtual void init();
        virtual void onCollision(ObjectHandler*, Entity* collider);
        virtual void update(ObjectHandler*);
        virtual void draw(double);

    protected:

    private:
        timer spawnTimer;
        bool canSpawn = true;
        int sTime;
        int sTimeLimit = 10000;
        float width = 0.04;
        float height = 0.04;
};

#endif // POWERUPSPAWN_H
