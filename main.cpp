#include "Table.h"
#include "Rocket.h"
#include "Ball.h"
#include <conio.h>
#include <windows.h>

using namespace std;
void menu(string s)
{
    system("mode con: cols=105 lines=35");//change Size Of Screen
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE ),14);
    system("cls");
    cout<<endl;
     cout<<"                  `.-::::::-.`                                                                    "<<endl;
     cout<<"              .:+osssssssssssso+:.                                     `-://+++/:-.`              "<<endl;
     cout<<"           ./ossssssssssssssssyyyso:`                              .:oyhhhddddddhhhys/-           "<<endl;
     cout<<"         .+ssssssssssssssssssssyyyyys/.                         `/shhdddddddddddddhhddhy+.        "<<endl;
     cout<<"        :syyysssssssssssssssssssyyyyyys/`                     .+hddddddddddddddddddddddddho.      "<<endl;
     cout<<"      `+yyyyyyyysysssssysssssyyyyyyyyyyys-                  `+hddddddddddddddddddddddddddddh/     "<<endl;
     cout<<"      /yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy:                -ydddddddddddddddddddddddddddddddh+    "<<endl;
     cout<<"     .yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy:              /ddddddddddddddddddddddddddddddddddh/   "<<endl;
     cout<<"     /yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy-            /ddddddddddddddddddddddddddddddddddddh.  "<<endl;
     cout<<"     oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy`          :dddddddmdddddddddddddddddddddddddddddd/  "<<endl;
     cout<<"     oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+         .dmdddmmmmmmddddddddddddddddddddddddddddo  "<<endl;
     cout<<"     /yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhy`        smmmmmmmmmmmmdddddddddddddddddddddddddddo  "<<endl;
     cout<<"     -yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhy`        dmmmmmmmmmmmmmdddddddddddddddddddddddddd/  "<<endl;
     cout<<"      oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyhhy`       `dmmmmmmmmmmmmmmmdddddddddddddddddddddddd.  "<<endl;
     cout<<"      .yyyyyyyyyyyyyyyyyyyyyyyyyyhhhhhhhhyhhh/         ommmmmmmmmmmmmmmmmmmdddddddddddddddddddo   "<<endl;
     cout<<"       :yhyyyyyyyyyyhyyyyhhhhhhhhhhhhhhhhhhy+          .hmmmmmmmmmmmmmmmmmmmdddddddddddddddddy`   "<<endl;
     cout<<"        :yhhyhyhhhhhhhhhhhhhhhhhhhhhhhhyso/.            .ohdmmmmmmmmmmmmmmmmmmddddddddddddddh.    "<<endl;
     cout<<"         -yhhhhhhhhhhhhhhhhhhhhhhhhyso/:-/               .:/oydmmmmmmmmmmmmmmmmmmmmmdmmmdddy.     "<<endl;
     cout<<"          `+hhhhhhhhhhhhhhhhhhhyyss+:::-/                   -:/oshdmmmmmmmmmmmmmmmmmmmmmmdo`      "<<endl;
     cout<<"            -shhhhhhhhhhhhhhyso/:::s+:/                      :/:::/yhdmmmmmmmmmmmmmmmmmmy:        "<<endl;
     cout<<"              -+yhhhhhhhhyo/:-:::::/so/                     ///:--+/-+ydmmmmmmmmmmmmmmh/`         "<<endl;
     cout<<"                `.:+oss+:-....-:/:::/so                     /+/::/o/-:::/oydmmmmmmmdho:`           "<<endl;
     cout<<"                                   `.:/:                    -.-+/::/s/:-..````.:+oo+/              "<<endl;
     cout<<"                                 `-+/:/so                .+/::+s:-`                               "<<endl;
     cout<<"                                   `++ommh+             -+/::oo:.                                 "<<endl;
     cout<<"                                    `+omNNdo           //::/s+-`                                  "<<endl;
     cout<<"                                     `+sNmNdo         +/::+s/-`                                   "<<endl;
     cout<<"                                      `osmmNh+       o/::os/-                                     "<<endl;
     cout<<"                                       `ooyssy+     +///ss/-                                      "<<endl;
     cout<<"                                        -s+++sh+:-/+//+yo/-                                       "<<endl;
     cout<<"                                         /s++/-`   `.:y+/-                                        "<<endl;
     cout<<"\t\t\t\t    "<<s;
}

int main()
{
    menu("WellCome To My Ping Pong Game");
    getch();
    while(1)
    {
        system("cls && mode con: cols=95 lines=26");//change Size Of Screen

        //Informations of table
        int x=0,
            y=1,
            width=95,
            height=25,
            color=15;

        Table table(x,y,width,height,color);
        table.print();

        //Informations of Rocket 1
        int size=3;
        x=2;
        y=height/2;
        color=12;

        Rocket pad1(x,y,size,color,&table);
        pad1.print();

        //Informations of Rocket 2
        x=width-3;
        color=11;

        Rocket pad2(x,y,size,color,&table);
        pad2.print();

        //Informations of Ball
        x=3;
        y=3;
        color=13;
        Ball ball(x,y,color,&table);

        //Play game
        int time=100;
        bool pause=false;
        bool reset=false;
        char c;
        while(ball.getP1Score()!=10 && ball.getP2Score()!=10 && !reset)
        {
            if(pause)
            {
                gotoxy(table.getX()+32,table.getY()-1);
                cout<<"Press Any Key To Continue";
                pause=false;
                getch();
                gotoxy(table.getX()+32,table.getY()-1);
                cout<<"                         ";
            }
            if(kbhit())// If Keys Has Pressed
            {
                c=getch();
                //Player 1
                if(c=='w')//Up
                {
                    pad1.move(true,false);
                    pad1.print();
                }
                else if(c=='s')//Down
                {
                    pad1.move(false,false);
                    pad1.print();
                }
                else if(c=='a')//Left
                {
                    pad1.move(true,true);
                    pad1.print();
                }
                else if(c=='d')//Right
                {
                    pad1.move(false,true);
                    pad1.print();
                }

                //Player 2
                if(c=='8')//Up
                {
                    pad2.move(true,false);
                    pad2.print();
                }

                else if(c=='2')//Down
                {
                    pad2.move(false,false);
                    pad2.print();
                }
                else if(c=='4')//Left
                {
                    pad2.move(true,true);
                    pad2.print();
                }

                else if(c=='6')//Right
                {
                    pad2.move(false,true);
                    pad2.print();
                }

                //Change Speed Of Ball
                if(c=='+')//Increase
                {
                    if(time > 50)
                        time-=5;
                }

                else if(c=='-')//Reduce
                {
                    if(time < 120)
                        time+=5;
                }
                if(c=='p')
                {
                    gotoxy(table.getX()+28,table.getY()-1);
                    cout<<"Do You Want To Exit Or Reset?Y/N/R";
                    c=getch();
                    if(c=='r' || c=='R')
                        reset=true;
                    else if (c=='y' || c=='Y')
                        exit(0);
                    else
                    {
                        gotoxy(table.getX()+28,table.getY()-1);
                    cout<<"                                  ";
                    }
                }
            }
                Sleep(time);
                ball.move();
                ball.reflex(pause);//Change Up & Right For Next Place
                ball.print();
        }
        if(ball.getP1Score()==10)
            menu("Congratulations!! Player #1 Win The Game");
        else if(ball.getP2Score()==10)
            menu("Congratulations!! Player #2 Win The Game");
        if(!reset)
        {
            gotoxy(36,33);
            cout<<"Do You Want Play Again?Y/N";
            c=getch();
            if(c=='n' || c=='N')
                exit(0);
        }
    }
    return 0;
}
