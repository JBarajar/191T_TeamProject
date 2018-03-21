#ifndef PLAYER_H
#define PLAYER_H

#include<Model.h>
#include<gl/gl.h>
#include<textureLoader.h>
#include<Trail.h>

typedef struct
{
   float x;
   float y;
   float z;
}vec;

class player:Model
{
    public:
        player();
        virtual ~player();

        float scalesize[3]={1.0,1.0,1.0};
        vec verticies[4];

        int runspeed;
        int jumpspeed;
        int actionTrigger;

        float speed = 0.01;
        int dir = 0;
        float rot = 0;

        void drawPlayer();
        void playerInit();
        void actions(int);
        void setDirection(int);
        void movePlayer();

        Trail trail;


    protected:

    private:
};

#endif // PLAYER_H
