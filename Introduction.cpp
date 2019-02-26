#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>

using namespace std;

class Introduction{
public :
    int x=170,y=50,offset = 20;
    int delayTime=200;

    Introduction(){
    }
    void introduceTeamMembers(){
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
        y=y+5*offset;
        delay(delayTime);
        outtextxy(x+7* offset,y,"By");
        y=y+2*offset;
        delay(delayTime);
        outtextxy(x,y,"Aashray Raj Sainju(073/BEX/302)");
        y=y+offset;
        delay(delayTime);
        outtextxy(x,y,"Gocool Raj Adhikari(073/BEX/311)");
        y=y+offset;
        delay(delayTime);
        outtextxy(x,y,"Krishna Rauniyar(073/BEX/318)");
        y=y+offset;
        delay(delayTime);
        outtextxy(x,y,"Nabin Pakka(073/BEX/320)");
    }
    void introduceProject(){
        settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
        outtextxy(x+2*offset,y,"Periodic Table");
    }

};
