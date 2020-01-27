

//	[SUPER ROUGH UML CHART] 
/*


	Everything below GameObject is part of its inheritance tree.
	The connection between GameManager and GameObject is a direct
	relationship, and not inheritance. GameManager HAS-A SDL object
	in it (GameManager is composed of 1 SDL object).
	


				GameManager<>-----SDL
					|
					|
				GameObject
				 ^	^	^
				/	|	 \
			   /	|	  \
			  /		|	   \
			 /		|		\
	    Character  Coin	   Border
	     ^	 ^      ^
		/	  \	     \
	   /  	   \	  \
	  /			\	   \
	Player	  Enemy    EvilCoin
				 ^		
			     |      
			     |		
			     |		
			  BigEnemy
	
*/


//	[RESOURCES] 
/*

Inheritance:
http://www.studytonight.com/cpp/overview-of-inheritance.php

Aggregation:
http://www.learncpp.com/cpp-tutorial/103-aggregation/

*/






//CLASSES
 #include "GameObject.h"
 #include "Character.h"
 #include "Player.h"
 #include "Enemy.h"
 #include "BigEnemy.h"
 #include "Coin.h"
 #include "EvilCoin.h"
 #include "Border.h"
 #include "GameManager.h"
 #include "SDLManager.h"
 #include "Rect.h"
 
//LIBRARIES
 #include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <memory>
 #include <string>
 #include <vector> 
 #include <SDL2/SDL.h>
 using namespace std; 
 
 
void processEvent(SDLManager* sdl, Rect* rect, Rect* rect2);
void processKeyEvent(SDL_Event e, SDLManager* sdl, Rect* rect);
bool checkCollision(Rect* a, Rect* b, std::string message);

const Uint8* state = NULL;
 
 
 int main()
 {
	    SDLManager* sdl;
    sdl = new SDLManager("Hello", 0, 0, 500, 500);
    SDL_Texture* img = sdl->loadTexture("test.bmp");
    
    
    //Player character is red
    Rect* player;
    player = new Rect();
    player->setAll(70, 50, 15, 15, 255, 139, 0);
    
    
    //Coin character is gold
    Rect* coin;
    coin = new Rect();
    coin->setAll(130, 50, 15, 15, 255, 215, 0);
    
    //enemy character which is pink
    Rect* enemy;
    enemy = new Rect();
    enemy->setAll(50, 50, 15, 15, 50, 50, 255);
    
    Rect* border;//right border
    border = new Rect();
    border->setAll(175, 0, 15, 100, 255, 0, 0);
    
    Rect* border2;//left border
    border2 = new Rect();
    border2->setAll(50, 0, 15, 100, 255, 0, 0);
    
    Rect* border3; //top border
    border3 = new Rect();
    border3->setAll(50, 0, 125, 15, 255, 0, 0);
    
    Rect* border4;//bottom border
    border4 = new Rect();
    border4->setAll(50, 100, 140, 15, 255, 0, 0);
    
    
    //checks for collision between enemy and player
    
    
    
    bool test = false;
    
    while(sdl->getWindow() != NULL)
    {
       
        sdl->setColor(0, 0, 0, 255);
        sdl->clear();
        
        processEvent(sdl, player, border);
        //Collision messages
        checkCollision(player,border,"Collision with right border");
        checkCollision(player, enemy, "Collision with enemy");
        checkCollision(player,coin, "Collision with coin");
        checkCollision(player,border2, "Collision with left border");
        checkCollision(player,border3, "Collision with top border");
        checkCollision(player,border4, "Collision with bottom border");
        
        //set object colors
        sdl->setColor(255, 0, 0, 255);
        sdl->drawRect(player->getX(), player->getY(), player->getW(), player->getH());
        
        sdl->setColor(241, 156, 187, 255);
        sdl->drawRect(enemy->getX(), enemy->getY(), enemy->getW(), enemy->getH());
        
        sdl->setColor(255, 215, 0, 255);
        sdl->drawRect(coin->getX(), coin->getY(), coin->getW(), coin->getH());
        
        sdl->setColor(0, 0, 255, 255);
        sdl->drawRect(border->getX(), border->getY(), border->getW(), border->getH());
        
        sdl->setColor(0, 0, 255, 255);
        sdl->drawRect(border2->getX(), border2->getY(), border2->getW(), border2->getH());
        
        sdl->setColor(0, 0, 255, 255);
        sdl->drawRect(border3->getX(), border3->getY(), border3->getW(), border3->getH());
        
        sdl->setColor(0, 0, 255, 255);
        sdl->drawRect(border4->getX(), border4->getY(), border4->getW(), border4->getH());
        
        if( !test )
        {
            enemy->update(5, 0);
            
            if(enemy->getX() >= 100)
            {
                test = true;
            }
        }
        else if(test)
        {
            enemy->update(-5,0);
            
            if(enemy->getX() <= 0)
            {
                test = false;
            }
        }
        
        
        
        sdl->refresh();
        SDL_Delay(300);
        
    }
 }
 
 
 bool checkCollision(Rect* a , Rect* b, std::string message)
 {
     //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a->getX();
    rightA = a->getX() + a->getW();
    
    topA = a->getY();
    bottomA = a->getY() + a->getH();

    //Calculate the sides of rect B
    leftB = b->getX();
    rightB = b->getX() + b->getW();
    topB = b->getY();
    bottomB = b->getY() + b->getH();
    
        //If any of the sides from A are outside of B
    if( bottomA <= topB)
    {
        std::cout << "No collision!" << std::endl;
        a->setH(15);
        a->setW(15);
        return false;
    }

    if( topA >= bottomB)
    {
        std::cout << "No collision!" << std::endl;
        a->setH(15);
        a->setW(15);
        return false;
    }

    if( rightA <= leftB )
    {
        std::cout << "No collision!" << std::endl;
        a->setH(15);
        a->setW(15);
        return false;
    }

    if( leftA >= rightB  )
    {
        std::cout << "No collision!" << std::endl;
        a->setH(15);
        a->setW(15);
        
        return false;
    }

    //If none of the sides from A are outside B
    std::cout << "Collision with" << message << std::endl;
    return true;
 }
 
//  bool checkCollision(Rect* a , Rect* b)
// {
//     //The sides of the rectangles
//     int leftA, leftB;
//     int rightA, rightB;
//     int topA, topB;
//     int bottomA, bottomB;

//     //Calculate the sides of rect A
//     leftA = a->getX();
//     rightA = a->getX() + a->getW();
    
//     topA = a->getY();
//     bottomA = a->getY() + a->getH();

//     //Calculate the sides of rect B
//     leftB = b->getX();
//     rightB = b->getX() + b->getW();
//     topB = b->getY();
//     bottomB = b->getY() + b->getH();
    
//         //If any of the sides from A are outside of B
//     if( bottomA <= topB)
//     {
//         std::cout << "No collision!" << std::endl;
//         a->setH(15);
//         a->setW(15);
//         return false;
//     }

//     if( topA >= bottomB)
//     {
//         std::cout << "No collision!" << std::endl;
//         a->setH(15);
//         a->setW(15);
//         return false;
//     }

//     if( rightA <= leftB )
//     {
//         std::cout << "No collision!" << std::endl;
//         a->setH(15);
//         a->setW(15);
//         return false;
//     }

//     if( leftA >= rightB  )
//     {
//         std::cout << "No collision!" << std::endl;
//         a->setH(15);
//         a->setW(15);
        
//         return false;
//     }

//     //If none of the sides from A are outside B
//     std::cout << "Collision detected!" << std::endl;
//     return true;
// }


void processEvent( SDLManager* sdl, Rect* rectA, Rect* rectB)
{
    SDL_Event e;
    
    while(SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
            case SDL_QUIT:
                sdl->close();
                break;
            case SDL_KEYDOWN:
                processKeyEvent(e, sdl, rectA);
                break;
        }
        //checkCollision(rectA,rectB);
        
    }
}


void processKeyEvent(SDL_Event e, SDLManager* sdl, Rect* rect)
{
   const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) 
    {
        rect->update(0,-2);
    }
    
    if (state[SDL_SCANCODE_DOWN]) 
    {
        rect->update(0,+2);
    }
    
    if (state[SDL_SCANCODE_LEFT]) 
    {
        rect->update(-2,0);
    }
    
    if (state[SDL_SCANCODE_RIGHT]) 
    {
        rect->update(+2,0);
    }
    
}
 
 
 
 