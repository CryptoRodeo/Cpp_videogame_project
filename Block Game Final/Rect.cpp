
#include "Rect.h"
#include <iostream>


void Rect::setAll(int x0, int y0, int w, int h, int r0, int g0, int b0)
{
    x = x0;
    y = y0;
    height = h;
    width= w;
    r = r0;
    g = g0;
    b = b0;
}

int Rect::setW(int w)
{
    width = w;
}

int Rect::setH(int h)
{
    height = h;
}

int Rect::getX()
{
    return x;
}

int Rect::getY()
{
    return y;
}

int Rect::getW()
{
   return width; 
}

int Rect::getH()
{
    return height;
}

void Rect::update(int x0, int y0)
{
    x += x0;
    
    if(x < 0)
    {
        x = 0;
    }
    y += y0;
    
    if(y < 0)
    {
        y = 0;
    }
}

Rect::Rect()
{
    x = 25;
    y = 25;
    height = 30;
    width = 30;
}