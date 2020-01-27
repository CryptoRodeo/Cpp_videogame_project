#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

class GameObject
{
	protected:
		
		int height, width;
		
		int posX, posY;
		
		int prevX, prevY;
		
		int red, green, blue, alpha;
		
		
		
	public:
		
	//	=================== SETTERS =====================

		void setHeight(int h);
		void setWidth(int w);
		
		void setCoords(int x, int y);
		void setPrevCoords(int x, int y);
		
		void setColor(int r, int g, int b, int a);

		
	//	=================== GETTERS =====================

		int getHeight();
		int getWidth();
		
		int getPosX();
		int getPosY();
		
		int getPrevX();
		int getPrevY();
		
		int getRed();
		int getGreen();
		int getBlue();
		int getAlpha();
		
		
	//	=================== CONSTRUCTORS ========================

		GameObject();
		GameObject(int height, int width, int posX, int posY);
	
	
	//	=================== OTHER FUNCTIONS =====================

		void printInfo();
};



#endif
