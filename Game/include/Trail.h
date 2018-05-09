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
        Trail();
        virtual ~Trail();

        void addPoint();
        void drawTrail();
        void updateEnds(float,float);
        void init(float, float);
        float getLength();
        std::vector<Point> getPoints() {return points;}

        void setSpeed(float s) {speed = s;}
        void setColor(float r, float g, float b) {color.r = r; color.g = g; color.b = b;}
        void setMaxLength(float l){maxLength = l;}

    protected:

    private:
        std::vector<Point> points;
        std::vector<Point>::iterator it;
        float maxLength = 0.5;
        Color color;
        float speed;
};

#endif // TRAIL_H
