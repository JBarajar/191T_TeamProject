#ifndef TRAIL_H
#define TRAIL_H

#include<windows.h>
#include<GL/glut.h>
#include<vector>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    float r, g, b;
} Color;

class Trail
{
    public:
        Trail(float, float, float);
        virtual ~Trail();

        void addPoint();
        void drawTrail();
        void updateEnds(float,float);
        void init(float, float);
        float getLength();

    protected:

    private:
        std::vector<Point> points;
        std::vector<Point>::iterator it;
        float maxLength = 1.0;
        Color color;
};

#endif // TRAIL_H
