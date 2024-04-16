#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;

void startpage()
{


        setactivepage(1);
        cleardevice();
        setvisualpage(1);

         readimagefile("car1.jpg",500,200,700,400);


        setcolor(10);
        settextstyle(9,HORIZ_DIR,9);
        outtextxy(350,30,"FUNNY");

        setcolor(4);

        outtextxy(250,100,"CAR  RACE");
        setcolor(15);
        settextstyle(3,HORIZ_DIR,5);
        outtextxy(200,400,"Control key:");
        outtextxy(200,450,"Car 1: A,D");
        outtextxy(200,500,"Car 2: Left key,Right key");

        setcolor(4);

        outtextxy(200,600,"Press left-shift key to start the game.");


        getch();




    return ;


}
void lost1()
{

    int loop;
    setactivepage(1);
    cleardevice();

    setvisualpage(1);
    setcolor(10);
    settextstyle(9,HORIZ_DIR,20);
    outtextxy(100,30,"PLAYER ONE IS ");
    setcolor(1);
    outtextxy(300,200,"LOST!");
    setcolor(15);
    for(loop=0; loop<90; loop++)
    {

        ellipse(700,200,0,360,70-loop,90-loop);   // --------egg

    }
    setcolor(14);
    for(loop=0; loop<50; loop++)
    {

        ellipse(700,263,0,360,70-loop,27-loop);   // --------egg

    }
    delay(2000);

    exit(1);
    return;
}

void lost2()
{
    int loop;
    setactivepage(1);
    cleardevice();
    setvisualpage(1);
    setcolor(10);
    settextstyle(9,HORIZ_DIR,20);
    outtextxy(100,30,"PLAYER TWO IS ");
    setcolor(4);
    outtextxy(300,200,"LOST!");
    setcolor(15);
    for(loop=0; loop<90; loop++)
    {

        ellipse(755,200,0,360,70-loop,90-loop);   // --------egg

    }
    setcolor(14);
    for(loop=0; loop<50; loop++)
    {

        ellipse(755,263,0,360,70-loop,27-loop);   // --------egg

    }
    delay(2000);

    exit(1);
    return;
}




//-----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------


int main()
{
    struct tm* ptr;//time pointer
    time_t start,end;//time variable
    float time_gap=0.0;
    int loop,cpos=0,c2pos=0,ex,e2x,page=0,ey=100,e2y=100,speed=10;//cpos=carposition,e=enemy

    int gd=DETECT,gm;

    initgraph(&gd,&gm,"");
    cleardevice();
    initwindow(1270,700);



    startpage();


label1 :




    ex=rand()%510+100;
    e2x=rand()%460+710;
    while(1)
    {
        start = time(NULL);

        setactivepage(1-page);

        setvisualpage(page);

        cleardevice();







        //enemy _________________________



        setcolor(15);
        for(loop=0; loop<50; loop++)
        {

            ellipse(ex,ey,0,360,40-loop,50-loop);   // --------egg
            ellipse(e2x,e2y,0,360,40-loop,50-loop);
        }

        setcolor(15);
        line(ex-20,ey-45,ex+20,ey-45);     //--------------collision line of car 1
        line(ex-35,ey+5,ex+35,ey+5);
        line(ex-20,ey+45,ex+20,ey+45);
        line(e2x-20,e2y+40,e2x+20,e2y+40);//-------------collision line of car 2

        line(e2x-35,e2y+5,e2x+35,e2y+5);
        line(e2x-20,e2y+45,e2x+20,e2y+45);
        ey+=speed;
        e2y+=speed;


        if(ey>720)
        {

            ey=100;
            e2y=100;
            goto label1;
        }

        //frame_______________________________
        setfillstyle(SOLID_FILL,3);
        bar(1,1,50,700);

        setfillstyle(SOLID_FILL,8);
        bar(610,1,660,700);

        setfillstyle(SOLID_FILL,3);
        bar(1220,1,1270,700);

        //-----------------------------keys______________keys__________keys_____________________
        if(GetAsyncKeyState(0x41))
        {
            cpos-=50;
            if(cpos<-100)
                cpos=350;
        }

        if(GetAsyncKeyState(0x44))
        {

            cpos+=50;
            if(cpos>390)
                cpos=-99;
        }


        if(GetAsyncKeyState(VK_LEFT))
        {
            c2pos-=50;
            if(c2pos<-100)
                c2pos=350;

        }
        else if (GetAsyncKeyState(VK_RIGHT))
        {

            c2pos+=50;
            if(c2pos>390)
                c2pos=-99;
        }
        for(loop=0; loop<60; loop++) //condition of collision-------1
        {
            if((ex-20+loop)==(cpos+200) && ey>455)
            {
                delay(100);
                lost1();
            }

            if((ex-20+loop)==(cpos+170) && ey>545)
            {
                delay(100);
                lost1();
            }

            if((ex-20+loop)==(cpos+260) && ey>545)
            {
                delay(100);
                lost1();
            }

        }

        if   (GetAsyncKeyState(VK_RSHIFT))
            delay(5000);


        for(loop=0; loop<60; loop++) //condition of collision------------2
        {
            if((e2x-20+loop)==(c2pos+800) && e2y>455)
            {
                delay(100);
                lost2();
            }
            if((e2x-20+loop)==(c2pos+740) && e2y>545)
            {
                delay(100);
                lost2();
            }
            if((e2x-20+loop)==(c2pos+860) && e2y>545)
            {
                delay(100);
                lost2();
            }
        }




        //car1--------------------------------------------------

        setcolor(RED);
        for(loop=0; loop<19; loop++)
            ellipse(200+cpos,535-40+50,0,180,93,20+loop);

        for(loop=0; loop<19; loop++)
        {

            ellipse(163+cpos,545,180,360,32,60+loop);
            ellipse(236+cpos,545,180,360,32,60+loop);
        }
        //side wall
        setfillstyle(SOLID_FILL,4);
        bar(123+cpos,533,128+cpos,615);
        bar(273+cpos,533,278+cpos,615);


        for(loop=0; loop<19; loop++)
            ellipse(200+cpos,545,0,180,32,90+loop);

        for(loop=0; loop<19; loop++)
            ellipse(200+cpos,615,0,180,79,160+loop);
        for(loop=0; loop<19; loop++)
            ellipse(200+cpos,615,180,360,79,40+loop);
        setfillstyle(SOLID_FILL,4);
        bar(121+cpos,615,278+cpos,625);

        for(loop=0; loop<5; loop++)
        {

            line(107+cpos,545-loop,293+cpos,545-loop);
        }

        //midline
        for(loop=0; loop<16; loop++)
            line(200+cpos,455,192+loop+cpos,615);
        //eye
        ellipse(160+cpos,561,0,360,15,27);
        ellipse(240+cpos,561,0,360,15,27);
        //teeth
        bar(178+cpos,615,198+cpos,635);
        bar(202+cpos,615,222+cpos,635);


        //--------------------collision line
        setcolor(4);
        line(170+cpos,455,230+cpos,455);


        line(110+cpos,545,170+cpos,545);
        line(230+cpos,545,290+cpos,545);




//    car 2----------------------------------------------



        setcolor(9);

        for(loop=0; loop<19; loop++)
            ellipse(800+c2pos,535-40+50,0,180,93,20+loop);

        for(loop=0; loop<19; loop++)
        {

            ellipse(763+c2pos,545,180,360,32,60+loop);
            ellipse(836+c2pos,545,180,360,32,60+loop);
        }
        //side wall
        setfillstyle(SOLID_FILL,9);
        bar(723+c2pos,533,728+c2pos,615);
        bar(873+c2pos,533,878+c2pos,615);


        for(loop=0; loop<19; loop++)
            ellipse(800+c2pos,545,0,180,32,90+loop);

        for(loop=0; loop<19; loop++)
            ellipse(800+c2pos,615,0,180,79,160+loop);
        for(loop=0; loop<19; loop++)
            ellipse(800+c2pos,615,180,360,79,40+loop);
        setfillstyle(SOLID_FILL,9);
        bar(721+c2pos,615,878+c2pos,625);

        for(loop=0; loop<5; loop++)
        {

            line(707+c2pos,545-loop,893+c2pos,545-loop);
        }

        //midline
        for(loop=0; loop<16; loop++)
            line(800+c2pos,455,792+loop+c2pos,615);
        //eye
        ellipse(760+c2pos,561,0,360,15,27);
        ellipse(840+c2pos,561,0,360,15,27);
        //teeth
        bar(778+c2pos,615,798+c2pos,635);
        bar(802+c2pos,615,822+c2pos,635);




        // -------------------------------collision line-------------2

        setcolor(9);
        line(770+c2pos,455,830+c2pos,455);


        line(710+c2pos,530,770+c2pos,530);
        line(830+c2pos,530,890+c2pos,530);




//    car 2----------------------------------------------

        readimagefile("iftekhar (2).jpg",703+c2pos,437,890+c2pos,647);


        //exit option
        setcolor(15);//-----------------EXIT OPTION
        settextstyle(3,HORIZ_DIR,3);
        outtextxy(55,1,"Press right-shift key to end the game.");



        page=1-page;

        delay(20);
        end=time(NULL);
        time_gap+=difftime(end,start );
        if(time_gap>10.00)
        {
            if(speed<31)
                speed+=10;
            time_gap=0.0;
        }

    }


    getch();
    closegraph();

    return 0;
}
