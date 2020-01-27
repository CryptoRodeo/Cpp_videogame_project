#ifndef _CHARACTER_H
#define _CHARACTER_H

#include "GameObject.h"

class Character : public GameObject
{
	protected:
		
		int maxVelocity;
		int velX, velY;
		
	public:
	
		//	=================== SETTERS =====================
		
		void setMaxVelocity(int x);
		void setVelocity(int x, int y);
		
		
		//	=================== GETTERS =====================
		
		int getMaxVelocity();
		int getVelX();
		int getVelY();
		
		//	=================== CONSTRUCTORS =====================
		
		Character();
		Character(int maxVel);
		
		//	=================== OTHER FUNCTIONS ==================
		
		virtual void move(int choice);
		
};

#endif
