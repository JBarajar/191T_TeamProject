#include "Trail.h"
#include <iostream>'
#include <math.h>

Trail::Trail()
{
    //ctor

    color.r = 1.0;
    color.g = 1.0;
    color.b = 1.0;
}

Trail::~Trail()
{
    //dtor
}

void Trail::init(float x, float y)
{
    Point p;
    p.x = x;
    p.y = y;
    points.push_back(p);
    points.push_back(p);
}


void Trail::addPoint()
{
    Point p;
    p.x = points.back().x;
    p.y = points.back().y;
    points.push_back(p);
}

void Trail::updateEnds(float x, float y)
{
    points.back().x = x;
    points.back().y = y;

    int dirx, diry;

    if(getLength() >= maxLength) {
        if(points.at(1).x - points.front().x > 0) dirx = 1;
        else if(points.at(1).x - points.front().x < 0) dirx = -1;
        else dirx = 0;

        if(points.at(1).y - points.front().y > 0) diry = 1;
        else if(points.at(1).y - points.front().y < 0) diry = -1;
        else diry = 0;

        points.front().x = points.front().x + (speed + 0.05) * dirx;
        points.front().y = points.front().y + (speed + 0.05) * diry;

        it = points.begin();
        if(points.size() > 2) {
            if(dirx == 1 && points.at(1).x - points.front().x <= 0) points.erase(it);
            else if(dirx == -1 && points.at(1).x - points.front().x >= 0) points.erase(it);
            else if(diry == 1 && points.at(1).y - points.front().y <= 0) points.erase(it);
            else if(diry == -1 && points.at(1).y - points.front().y >= 0) points.erase(it);
            else if(dirx == 0 && diry == 0) points.erase(it);
        }
    }
}

float Trail::getLength()
{
    float length = 0;
    for(int i = 0; i < points.size() - 1; i++) {
        length += sqrt(pow( points.at(i+1).x - points.at(i).x, 2) + pow(points.at(i+1).y - points.at(i).y,2));
    }
    return length;
}


void Trail::drawTrail()
{
    glBindTexture(GL_TEXTURE_2D, 0);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(color.r,color.g,color.b);
    glPointSize(5);

    glBegin(GL_POINTS);
        for(int i = 0; i < points.size()-1 ; i++) {
            float tx = 0, ty = 0;
            Point* p1 = &points.at(i);
            Point* p2 = &points.at(i+1);


            for(float t = 0.0; t <= 1.0; t += 0.001) {
                tx = p1->x + t * (p2->x - p1->x);
                ty = p1->y + t * (p2->y - p1->y);

                glVertex3f(tx,ty,-1.0);
            }
        }
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
        for(int i = 0; i < points.size() ; i++) {
            glVertex3f(points.at(i).x, points.at(i).y, -1.0);
        }
    glEnd();

    glColor3f(1.0,1.0,1.0);
}
