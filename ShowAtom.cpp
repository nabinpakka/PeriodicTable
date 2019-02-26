#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include"circle.cpp"
#include"ellipse.cpp"
#include"Lining.cpp"

#define PI 3.14

class ShowAtom{
private:
    int atomicNumber;
    int x_center= 150,y_center = 240;
    int radius_of_first_orbital =50;
    int radius_of_second_orbital= 2*radius_of_first_orbital;
    int electron_radius = 7;
    int headerX = 300;
    int valueX = headerX +250;
    float angle =0;
    void drawProtons(){
        float protonAngle = 0;
        float offset  = 360.0/atomicNumber;
        float radian = offset *(PI/180);
        float x_offset=electron_radius *cos(protonAngle);
        float y_offset=electron_radius * sin(protonAngle);
        if(atomicNumber ==1){
            Circle circle = Circle(x_center,y_center,electron_radius,true);
            circle.drawCircle();
        }
        else{
            for(int i=0;i<atomicNumber;i++){
                Circle circle = Circle(x_center +x_offset,y_center+y_offset,electron_radius,true);
                circle.drawCircle();
                x_offset = electron_radius *cos(protonAngle);
                y_offset = electron_radius *sin(protonAngle);
                protonAngle +=radian;
            }
        }
    }
    void drawElectrons(){
        //finding center of
        int x_electron = radius_of_first_orbital * cos(angle);
        int y_electron = radius_of_first_orbital * sin(angle);


        if(atomicNumber==1){
            Circle electron1=Circle(x_center+x_electron,y_center+y_electron,electron_radius,true);
            electron1.drawCircle();
        }
        else{
            for(int i=0;i<2;i++){
                Circle electron1=Circle(x_center+x_electron,y_center+y_electron,electron_radius,true);
                electron1.drawCircle();
                float singleAngle = angle;
                singleAngle +=PI;
                x_electron=radius_of_first_orbital * cos(singleAngle);
                y_electron = radius_of_first_orbital * sin(singleAngle);
            }
            if(atomicNumber>2){
                float offset = 360.0/(atomicNumber-2);
                float radian = offset *(PI/180);
                float doubleAngle = angle;
                for(int i=0;i<atomicNumber-2;i++){
                    x_electron=radius_of_second_orbital * cos(doubleAngle);
                    y_electron = radius_of_second_orbital * sin(doubleAngle);
                    Circle electron1=Circle(x_center+x_electron,y_center+y_electron,electron_radius,true);
                    electron1.drawCircle();
                    doubleAngle +=radian;
                }
            }
        }
    }

    void drawOrbitals(){
        Circle orbital1 = Circle (x_center,y_center,radius_of_first_orbital,false);
        orbital1.drawCircle();
        if(atomicNumber>2){
            Circle orbital2= Circle(x_center,y_center,radius_of_second_orbital,false);
            orbital2.drawCircle();
        }
    }
    void displayInfo(int atno)
    {
        int proton, neutron, atwt, electron, val;
        switch (atno)
        {
            case 1:
            {
                outtextxy(valueX, 150, "Hydrogen");
                proton = atno;
                electron = atno;
                neutron = 0;
                val = 1;
                break;
            }
        case 2:
        {
            outtextxy(valueX, 150, "Helium");
            proton = atno;
            electron = atno;
            neutron = 2;
            val = 0;
            break;
        }
        case 3:
        {
            outtextxy(valueX, 150, "Lithium");
            proton = atno;
            electron = atno;
            neutron = 4;
            val = 1;
            break;
        }
        case 4:
        {
            outtextxy(valueX, 150, "Berrylium");
            proton = atno;
            electron = atno;
            neutron = 5;
            val = 2;
            break;
        }
        case 5:
        {
            outtextxy(valueX, 150, "Boron");
            proton = atno;
            electron = atno;
            neutron = 6;
            val = 3;
            break;
        }

        case 6:
        {
        outtextxy(valueX, 150, "Carbon");
        proton = atno;
        electron = atno;
        neutron = 6;
        val = 4;
        break;
        }
        case 7:
        {
        outtextxy(valueX, 150, "Nitrogen");
        proton = atno;
        electron = atno;
        neutron = 7;
        val = 3;
        break;
        }
        case 8:
        {
        outtextxy(valueX, 150, "Oxygen");
        proton = atno;
        electron = atno;
        neutron = 8;
        val = 2;
        break;
        }

        case 9:
        {
        outtextxy(valueX, 150, "Flourine");
        proton = atno;
        electron = atno;
        neutron = 10;
        val = 1;
        break;
        }
        case 10:
        {
        outtextxy(valueX, 150, "Neon");
        proton = atno;
        electron = atno;
        neutron = 10;
        val = 0;
        break;
        }
    }

    atwt = proton + neutron;
    outtextxy(headerX , 150, "Name:");
    outtextxy(headerX , 175, "Number of proton:");
    outtextxy(headerX , 200, "Number of neutron:");
    outtextxy(headerX , 225, "Number of electron:");
    outtextxy(headerX , 250, "Valency:");
    outtextxy(headerX , 275, "Atomic weight:");

    char temp_disp_arr[10];

    sprintf(temp_disp_arr, "%d", proton);
    outtextxy(valueX, 175, temp_disp_arr);

    sprintf(temp_disp_arr, "%d", neutron);
    outtextxy(valueX, 200, temp_disp_arr);

    sprintf(temp_disp_arr, "%d", proton);
    outtextxy(valueX, 225, temp_disp_arr);

    sprintf(temp_disp_arr, "%d", val);
    outtextxy(valueX, 250, temp_disp_arr);

    sprintf(temp_disp_arr, "%d", atwt);
    outtextxy(valueX, 275, temp_disp_arr);
}

void atomicConfig(int temp_atno)
{
    //for x coordinates
    int x_offset = 15;
    int temp1 = temp_atno;

    outtextxy(headerX, 300, "Atomic configuration:");

    char arr[50];
    sprintf(arr, "%d", temp_atno);
    valueX -=100;
    int y=320;

    if (temp_atno <= 2)
    {
        outtextxy(valueX, y, arr);
        outtextxy(valueX + x_offset, y, "s1");
    }
    else
    {
        outtextxy(valueX, y, "2");
        valueX =valueX+x_offset;
        outtextxy(valueX, y, "s1");

        if (temp_atno-2 <= 2)
        {
            temp1 = temp_atno - 2;
            sprintf(arr, "%d", temp1);
            valueX =valueX+x_offset;
            outtextxy(valueX, y, arr);
            valueX =valueX+x_offset;
            outtextxy(valueX, y, "s2");
        }
        else
        {
            valueX+=x_offset;
            outtextxy(valueX, y, "2");
            valueX+=x_offset;
            outtextxy(valueX, y, "s2");
            temp_atno -= 4;
            sprintf(arr, "%d", temp_atno);
            valueX+=30;
            outtextxy(valueX, y, "2p");
            valueX+=x_offset;
            outtextxy(valueX, y, arr);

        }
    }
}
public:
    ShowAtom(int number){
        atomicNumber= number;
    }
    void showAtomicInfo(){
        drawProtons();
        drawOrbitals();
        drawElectrons();
        displayInfo(atomicNumber);
        atomicConfig(atomicNumber);
        outtextxy(200,400,"For animation please click a");
        char ch = getch();
        char che = getch();
        if(ch == 'a' || che == 'a'){
            while(true){
                drawOrbitals();
                drawElectrons();
                drawProtons();
                delay(250);
                cleardevice();
                angle +=0.2;

            }
        }else{
            cleardevice();
            outtextxy(200,235,"Thank you for using our application");
            getch();
        }
    }
};
