#include <iostream>

#include "GameObject.h"
#include "Character.h"
#include "Player.h"



void Player::move(int n)
{
    switch(n)
    {
        case 1:
            std::cout << "Moving Up\n";
            break;
        case 2:
            std::cout << "Moving Down\n";
            break;
        case 3:
            std::cout << "Moving Left\n";
            break;
        case 4:
            std::cout << "Moving Right\n";
            break;
    }
}

Player::Player()
{
    
}
