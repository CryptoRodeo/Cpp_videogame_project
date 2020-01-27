#include <iostream>
#include "GameObject.h"



//	=================== SETTERS =====================

void GameObject::setHeight(int h)
{
	if(h >= 0)
	{
		height = h;
	}
	else 
	{
		height = 0;
	}
}

void GameObject::setWidth(int w)
{
	if(w >= 0)
	{
		width = w;
	}
	else 
	{
		width = 0;
	}
}

void GameObject::setCoords(int x, int y)
{
	if(x >= 0)
	{
		posX = x;
	}
	else
	{
		posX = 0;
	}
	
	if(y >= 0)
	{
		posY = y;
	}
	else
	{
		posY = 0;
	}
}

void GameObject::setPrevCoords(int x, int y)
{
	if(x >= 0)
	{
		prevX = x;
	}
	else
	{
		prevY = 0;
	}
	
	if(y >= 0)
	{
		prevX = y;
	}
	else
	{
		prevY = 0;
	}
}

void GameObject::setColor(int r, int g, int b, int a)
{
	if(r < 0 || r > 255)
	{
		red = 255;
	}
	else
	{
		red = r;
	}
	
	if(g < 0 || g > 255)
	{
		green = 255;
	}
	else
	{
		green = g;
	}
	
	if(b < 0 || b > 255)
	{
		blue = 255;
	}
	else
	{
		blue = b;
	}
	
	if(a < 0 || a > 255)
	{
		alpha = 255;
	}
	else
	{
		alpha = a;
	}
	
	
}


//	=================== GETTERS =====================

int GameObject::getHeight()
{
	return height;
}

int GameObject::getWidth()
{
	return width;
}

int GameObject::getPosX()
{
	return posX;
}

int GameObject::getPosY()
{
	return posY;
}

int GameObject::getPrevX()
{
	return prevX;
}

int GameObject::getPrevY()
{
	return prevY;
}

int GameObject::getRed()
{
	return red;
}

int GameObject::getGreen()
{
	return green;
}

int GameObject::getBlue()
{
	return blue;
}

int GameObject::getAlpha()
{
	return alpha;
}



//	=================== CONSTRUCTORS =====================

GameObject::GameObject()
{
	height = 10;
	width = 10;
	
	posX = 0;
	posY = 0;
	
	prevX = 0;
	prevY = 0;
	
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
}

GameObject::GameObject(int height, int width, int posX, int posY)
{
	this->height = height;
	this->width = width;
	
	this->posX = posX;
	this->posY = posY;
	
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}



//	=================== OTHER FUNCTIONS =====================

void GameObject::printInfo()
{
	std::cout << "\n =========================\n";
	std::cout << "       OBJECT INFO\n";
	std::cout << " =========================\n\n";
	
	std::cout << "Height: " << getHeight() << std::endl;
	std::cout << "Width: " << getWidth() << std::endl;
	
	std::cout << "\nPosition X: " << getPosX() << std::endl;
	std::cout << "Position Y: " << getPosY() << std::endl;
	
	std::cout << "\n[Color] R: " << getRed() << " G: " << getGreen()
	<< " B: " << getBlue() << " A: " << getAlpha() << std::endl << std::endl;
}