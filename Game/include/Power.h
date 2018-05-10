#ifndef POWER_H
#define POWER_H

#include <PowerUp.h>

class Power : public PowerUp
{
    public:
        Power(float, float);
        virtual ~Power();

    protected:

    private:

        //char* image = "images/DCell.png";
};

#endif // POWER_H
