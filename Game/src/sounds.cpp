#include "sounds.h"
#include <iostream>

using namespace std;

irrklang::ISoundEngine* engine = irrklang::createIrrKlangDevice();

sounds::sounds()
{
    //ctor
}

sounds::~sounds()
{
    //dtor
    engine->drop();
}
void sounds::playMusic(char* File)
{
    engine->play2D(File,true);
}

void sounds::playSound(char* File)
{
    engine->play2D(File,false,false);
}

void sounds::stopAllSounds()
{
    engine->stopAllSounds();
}

int sounds::initSounds()
{
    if(!engine)
    {
       cout<<"Could not Start the engine\n";
       return 0;
    }
    return 1;
}
