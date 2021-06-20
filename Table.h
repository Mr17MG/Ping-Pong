#ifndef TABLE_H
#define TABLE_H
#include <windows.h>
#include <iostream>

using namespace std;
/**********************For Change Cursor Of KeyBoard******************************/
void gotoxy(int x,int y)
{
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/*********************************************************************************/
class Table
{
    public:
        Table(int x,int y,int width,int height,int color)
        {
            this->x=x;//Horizontal location on page
            this->y=y;//Vertical location on page
            this->width=width;//Width Value of Table
            this->height=height;//Height Value of Table
            this->color=color;
            screen=new int*[height];
            for(int i=0;i<height;i++)
                screen[i]=new int[width];//Build a two-dimensional array of tables

            for(int i=0;i<height;i++)
                for(int j=0;j<width;j++)
                    screen[i][j]=0;//Zeroing a Entire Of Array

            for(int i=0;i<width;i++)
            {
                screen[0][i]=1;//Mark The Upper Border of The Table
                screen[height-1][i]=1;//Mark The Bottom Border of The Table
            }


            for(int i=0;i<height;i++)
            {
                screen[i][0]=2;//Mark The Left Border of The Table (Gate Of Player #one)
                screen[i][width-1]=3;//Mark The Right Border of The Table (Gate Of Player #two)
                screen[i][width/2]=5;//Mark The Center of The Table
            }
        }

        void print();// Print Of Table
        bool isInTable(int x,int y);//Is the ball in the table?
        void setElement(int x,int y,int element);//Set Element In Array
        int getElement(int x,int y);//Get Element of Array
        void setX(int X);
        int getX();
        void setY(int Y);
        int getY();
        void setWidth(int width);//Set Width Of Table
        int getWidth();
        void setHeight(int height);//Set Height Of Table
        int getHeight();

        ~Table()
        {
            for(int i=0;i<height;i++)
                delete screen[i];
            delete screen;//Delete Entire of Array
        }
    protected:

    private:
        int **screen;//Pointer To Pointer For Create 2D Array
        int x,y;//for place of table in screen
        int width,height;//for size of table
        int color;
};
/*********************************************************************************/

void Table::print()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE ),color);//Set Color Of Text
    for(int i=0;i<width;i++)
    {
        if(i==0)
        {
            gotoxy(i+x,y);//Upper-Left corner
            cout<<(char)201;
            gotoxy(i+x,height+y-1);//Bottom-Left corner
            cout<<(char)200;
        }
        else if(i==width/2)
        {
            gotoxy(i+x,y);//Center Of Table in Top Boarder
            cout<<(char)209;
            gotoxy(i+x,height+y-1);//Center Of Table in Bottom Boarder
            cout<<(char)207;
        }
        else if(i==width-1)
        {
            gotoxy(i+x,y);//Upper-Right corner
            cout<<(char)187;
            gotoxy(i+x,height+y-1);//Bottom-Right corner
            cout<<(char)188;
        }
        else
        {
            gotoxy(i+x,y);//Top Boarder
            cout<<(char)205;
            gotoxy(i+x,height+y-1);//Bottom Boarder
            cout<<(char)205;
        }
    }
    for(int i=1;i<height-1;i++)
    {
            gotoxy(x,i+y);//Left Boarder
            cout<<(char)186;
            gotoxy(x+(width/2),i+y);//The Line in Center of Table
            cout<<(char)245;
            gotoxy(width+x-1,i+y);//Right Boarder
            cout<<(char)186;
    }
}

/*********************************************************************************/

bool Table::isInTable(int x,int y)
{
    if(screen[x][y]==0)
        return true;
    else return false;
}

/*********************************************************************************/

void Table::setElement(int x,int y,int element)
{
    if(x>=0 && x<height && y>=0 && y<width )// if x&y in Of Range Do It
        screen[x][y]=element;
    else return;
}

/*********************************************************************************/

int Table::getElement(int x,int y)
{
    if(x>=0 && x<height && y>=0 && y<width )// if x&y in Of Range Do It
        return screen[x][y];
    else return -1;
}

/*********************************************************************************/

void Table::setX(int x)
{
    this->x=x;
}

/*********************************************************************************/

int Table::getX()
{
    return x;
}

/*********************************************************************************/

void Table::setY(int y)
{
    this->y=y;
}

/*********************************************************************************/

int Table::getY()
{
    return y;
}

/*********************************************************************************/

void Table::setWidth(int width)
{
    this->width=width;
}

/*********************************************************************************/

int Table::getWidth()
{
    return width;
}

/*********************************************************************************/

void Table::setHeight(int height)
{
    this->height=height;
}

/*********************************************************************************/

int Table::getHeight()
{
    return height;
}

/*********************************************************************************/
#endif // TABLE_H
