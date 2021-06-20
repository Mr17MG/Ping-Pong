#ifndef BALL_H
#define BALL_H
#include <Table.h>

/*********************************************************************************/
class Ball
{
    public:
        Ball(int x,int y,int color,Table *table)
        {
            this->x=x;//Horizontal location on page
            this->y=y;//Vertical location on page
            this->table=table;
            table->setElement(y,x,7);// Set 7 For Ball in Array
            up=1;////Vertical location on page Will Increase
            right=1;//Horizontal location on page Will Increase
            p1Score=0;//Score Of Player #one
            p2Score=0;//Score Of Player #two
            this->color=color;//Color OF Ball
        }
        ~Ball(){}

        void move();//For Movement Of Ball
        void print();//Print Of Ball
        void reflex(bool &pause);//For Change the direction of the ball
        void setX(int X);//Set Horizontal location on page
        int getX();//Get Horizontal location on page
        void setY(int Y);//Set Vertical location on page
        int getY();//Get Vertical location on page
        int getP1Score();//For Get Score Of Player #one
        int getP2Score();//For Get Score Of Player #two
    protected:

    private:
        int x,y;//for place of Ball
        int up,right;//For Next Place
        int p1Score,p2Score;//Scores Of Players
        int color;//Color Of Ball
        Table *table;
};
/*********************************************************************************/

void Ball::print()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE ),color);//Set Color Of Text
    if(table->getElement(y,x)==7)//Print Ball in x,y Of Screen
    {
        gotoxy(table->getX()+x,table->getY()+y);
        cout<<(char)233;
    }
    gotoxy(table->getX()+15,table->getY()-1);
    cout<<"Player 1:"<<p1Score;
    gotoxy(table->getX()+65,table->getY()-1);
    cout<<"Player 2:"<<p2Score;
}

/*********************************************************************************/

void Ball::move()
{
    if(table->getElement(y,x)==7)
    {
        table->setElement(y,x,0);//Set 0 Previous Place OF Rockets
        gotoxy(table->getX()+x,table->getY()+y);
        cout<<' '; //Clear Of Previous Place OF Rockets
    }
    y+=up;//Next Horizontal location
    x+=right;//Next Vertical location
    if(table->getElement(y,x)==0)
        table->setElement(y,x,7);//Set 7 New Place Of Rockets If is InTable
}

/*********************************************************************************/

void Ball::reflex(bool &pause)
{
    int temp=table->getElement(y+up,x+right);//Get Element of Next Place
    if(temp==1)//if top boarder or bottom boarder -> change Direction of Up or Down
    {
        if(up==1)
            up=-1;
        else up=1;
    }
    else if(temp==4)//if Collision To Rockets ->change Direction of Left or Right
    {
        if(right==1)
            right=-1;
        else right=1;
    }
    else if(temp==2)//player2Score
    {
        p2Score++;
        pause=true;
        x=table->getWidth()-5;//Next Horizontal Place For Start
        y=table->getHeight()-15;//Next Vertical Place For Start
        up=1;
        right=-1;
    }
    else if(temp==3)//player1Score
    {
        p1Score++;
        pause=true;
        x=table->getX()+5;//Next Horizontal Place For Start
        y=table->getY()+5;//Next Vertical Place For Start
        up=1;
        right=1;
    }
}
/*********************************************************************************/

void Ball::setX(int x)
{
    this->x=x;
}
/*********************************************************************************/

int Ball::getX()
{
    return x;
}

/*********************************************************************************/

void Ball::setY(int y)
{
    this->y=y;
}

/*********************************************************************************/

int Ball::getY()
{
    return y;
}

/*********************************************************************************/
int Ball::getP1Score()
{
    return p1Score;
}

/*********************************************************************************/

int Ball::getP2Score()
{
    return p2Score;
}

/*********************************************************************************/
#endif // BALL_H
