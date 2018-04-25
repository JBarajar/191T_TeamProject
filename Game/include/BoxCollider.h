#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include<string>


class BoxCollider
{
    public:
        BoxCollider(float width, float height, std::string tag);
        virtual ~BoxCollider();

        void setPosition(float, float);

        std::string getTag() {return tag;}
        float getLeft() {return xpos;}
        float getTop() {return ypos;}
        float getRight() {return xpos + width;}
        float getBot() {return ypos + height;}


    protected:

    private:
        float xpos, ypos;
        float width, height;
        std::string tag;

};

#endif // BOXCOLLIDER_H
