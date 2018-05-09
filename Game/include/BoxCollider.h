#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include<string>

typedef struct
{
   float x;
   float y;
   float z;
}vec;

class BoxCollider
{
    public:
        BoxCollider(float width, float height, std::string tag);
        virtual ~BoxCollider();
        vec verticies[4];

        void setPosition(float, float);

        std::string getTag() {return tag;}
        float getLeft() {return xpos-width/2.0;}
        float getTop() {return ypos+height/2.0;}
        float getRight() {return xpos + width/2.0;}
        float getBot() {return ypos - height/2.0;}
        float getX() {return xpos;}
        float getY() {return ypos;}

        void setWidth(float w) {width = w;}
        void setHeight(float h) {height = h;}
        void setTag(std::string s) {tag = s;}

        void drawCollider();


    protected:


    private:
        float xpos, ypos;
        float width, height;
        std::string tag;

};

#endif // BOXCOLLIDER_H
