#include<iostream>
#include<stdio.h>
#include<graphics.h>

class Lining{
public:
    int x,y,dx,dy,steps;
    float xi,yi;

    Lining(){

    }
    void drawLine(int x0,int y0,int x1,int y1){
        //not in constructor as we can draw many lines
        //from single object
        x = x0;
        y = y0;
        dx = x1-x0;
        dy = y1 -y0;

        steps=abs(dx) > abs(dy) ? abs(dx) : abs(dy);
        xi = dx/(float)steps;
        yi = dy /(float) steps;

        for (int i =0; i<=steps; i++){
            putpixel(x,y,RED);
            x+=xi;
            y+=yi;
        }
    }
};
