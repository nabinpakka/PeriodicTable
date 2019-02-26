#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#define row 8
#define column 2

using namespace std;

class Circle{

private:
    int radius;
    int cx,cy;
    int counter =0;
    bool isFilled = false;

public:

    ~Circle(){
        cout<<"destroyed"<<endl;
    }
    Circle(int x,int y,int radii,bool isFill){
        radius = radii;
        cx = x;
        cy = y;
        isFilled = isFill;

    }
    void circleOnly(int points[row][column]){
        int i;
        for (i=0;i<row;i++){
            putpixel(points[i][0],points[i][1],5);
        }
    }
    void drawFilledCircle(int points[row][column]){
        int x,x1,y;
        int i,j;
        for (i=0;i<row;i+=2){
             x=points[i+1][0];
             x1=points[i][0];
             y = points[i][1];

             while(x<=x1){
                putpixel(x,y,5);
                x++;
             }
        }
    }

    int** drawCircle(){

        //for circle points
        int x = radius, y = 0;
        int octantsPoints[row][column];

        // Initialising the value of P
        int P = 1 - radius;
        while (x >y )
        {
            y++;

            // Mid-point is inside or on the perimeter
            if (P <= 0)
                P = P + 2*y + 1;
            // Mid-point is outside the perimeter
            else
            {
                x--;
                P = P + 2*y - 2*x + 1;
            }
            counter++;
            octantsPoints[0][0]=x+cx;
            octantsPoints[1][0]=-x+cx;
            octantsPoints[2][0]=x+cx;
            octantsPoints[3][0]=-x+cx;
            octantsPoints[4][0]=y+cx;
            octantsPoints[5][0]=-y+cx;
            octantsPoints[6][0]=y+cx;
            octantsPoints[7][0]=-y+cx;

            octantsPoints[0][1]=y+cy;
            octantsPoints[1][1]=y+cy;
            octantsPoints[2][1]=-y+cy;
            octantsPoints[3][1]=-y+cy;
            octantsPoints[4][1]=x+cy;
            octantsPoints[5][1]=x+cy;
            octantsPoints[6][1]=-x+cy;
            octantsPoints[7][1]=-x+cy;

            if(isFilled){
                drawFilledCircle(octantsPoints);
            }else{
                circleOnly(octantsPoints);
            }

        }
        if(isFilled){//here a is the variable to make the central line
            //for central line of the circle
            int i;
            for(i=cy-2;i<=cy+2;i++){
                int a = cx-radius;
                while(a<= (cx+radius)){
                    putpixel(a,i,5);
                    a++;
                }

            }
        }
    }
};


