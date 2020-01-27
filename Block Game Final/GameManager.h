#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H

#include "SDLManager.h"
#include "Player.h"

class GameManager
{

    protected:
        
        SDLManager* sdlManager;
        
        //Player* p1;

    public:
    
        void setUp();
    
        void play();
        
        void close();
};

#endif
