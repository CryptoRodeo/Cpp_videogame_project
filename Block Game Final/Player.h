#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameObject.h"
#include "Character.h"




class Player : public Character
{
    
    protected:
    
    public:
    
        void move(int n);
        
        Player();
};



#endif