

#ifndef _RECT_H
#define _RECT_H

class Rect
{
    private:
        int x;
        int y;
        int r;
        int g;
        int b;
        int width;
        int height;
    
    public:
        void setAll(int x, int y, int w, int h, int r, int g, int b);
        int setW(int w);
        int setH(int h);
        int getX();
        int getY();
        int getW();
        int getH();
        void update(int, int);
        Rect();
};
#endif 