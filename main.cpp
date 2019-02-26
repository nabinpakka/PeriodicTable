#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include"Introduction.cpp"
#include"ShowAtom.cpp"

void getStarted(){
    getch();
    cleardevice();
    outtextxy(200,235,"Enter atomic number up to 10");
    int atno;
    std ::cin>>atno;
    std::cout<<atno<<endl;
    cleardevice();
    if(atno <=10 && atno >0){
        ShowAtom showAtom  =ShowAtom(atno);
        showAtom.showAtomicInfo();
        getch();
    }
    else{
        outtextxy(200,235,"Invalid number !!Try again");
        getch();
        getStarted();
    }
}
int main(){
    int gd = DETECT,gm;           // Initialise the graphics system
    initgraph(&gd,&gm,"c:\\tc\\bgi");

    //accessing dimension of laptop
    /*DWORD SCREEN_WIDTH =GetSystemMetrics(SM_CXSCREEN);//1366
    DWORD SCREEN_HEIGHT =GetSystemMetrics(SM_CYSCREEN);//768
    cout<<SCREEN_HEIGHT<<"   "<<SCREEN_WIDTH;
    initwindow(SCREEN_WIDTH,SCREEN_HEIGHT);
    */

    //width of graphics window = 640
    //height of graphics window = 480
    //++++++++++++++++++++++++++++++++INTRODUCTION PART ++++++++++++++++++++++++++++++++++++++
    Introduction introduction = Introduction();
    introduction.introduceProject();
    introduction.introduceTeamMembers();
    getStarted();
    return 0;
}
