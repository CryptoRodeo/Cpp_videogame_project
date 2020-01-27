#include <iostream>
#include "GameObject.h"
#include "Character.h"

//	=================== SETTERS =====================

void Character::setMaxVelocity(int x)
{
	int limit = 10;
	
	if(x < 0 || x > limit)
	{
		maxVelocity = 1;
	}
	else
	{
		maxVelocity = x;
	}
}

void Character::setVelocity(int x, int y)
{
	int limit = 10;
	
	if(x < 0 || x > limit)
	{
		velX = 0;
	}
	else
	{
		velX = x;
	}
	
	if(y < 0 || y > limit)
	{
		velY = 0;
	}
	else
	{
		velY = y;
	}
}


//	=================== GETTERS =====================

int Character::getMaxVelocity()
{
	return maxVelocity;
}

int Character::getVelX()
{
	return velX;
}

int Character::getVelY()
{
	return velY;
}


//	=================== CONSTRUCTORS =====================

Character::Character()
{
	posX = 0;
	maxVelocity = 10;
	velX = 0;
	velY = 0;
}

Character::Character(int maxVel)
{
	posX = 0;
	setMaxVelocity(maxVel);
	velX = 0;
	velY = 0;
}

		
//	=================== OTHER FUNCTIONS ==================

void Character::move(int choice)
{
	
	
	//Choice 1 = X axis movement - left and right
	//Choice 2 = Y axis movement - up and down
	
	if(choice = 1)
	{
		prevX = posX;
		posX += velX;
		
		if((posX < 0) || (posX + width > 640))
		{
			posX = prevX;
		}
	}

	
	if(choice = 2)
	{
		prevY = posY;
		posY += velY;
	
		if((posY < 0) || (posY + height > 480))
		{
			posX = prevX;
		}
	}
}
