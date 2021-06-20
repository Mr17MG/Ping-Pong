#ifndef ROCKET_H
#define ROCKET_H


class Rocket
{
    public:
        Rocket(int x,int y,int size,int color,Table *table)
        {
            this->x=x;//Horizontal location on page
            this->y=y;//Vertical location on page
            this->size=size;//The Size Of Rocket
            this->color=color;//The Color Of Rocket
            this->table=table;
            for(int i=0,k=y;i<size;i++)
                table->setElement(k++,x,4);// Set 4 For Rockets in Array
        }

        void print();//Print Of Rockets
        void move(bool up,bool right);//Movement Of Rockets

    protected:

    private:
        int x,y;//for place of Rocket
        int size;//for size of Rocket
        int color;//for color of Rocket
        Table *table;
};

/*********************************************************************************/

void Rocket::print()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE ),color);//Set Color Of Text

    for(int i=1;i<table->getHeight()-1;i++)
    {
        gotoxy(x+table->getX(),i+table->getY());

        if(table->getElement(i,x)==4)// For Move to Top Or Right & Print Rockets
            cout<<(char)219;
        else cout<<" ";

        if(table->getElement(i,x-1)==0)// For Move to Right & Clear Of Previous Place OF Rockets
        {
            gotoxy(x-1+table->getX(),i+table->getY());
            cout<<" ";
        }
        if(table->getElement(i,x+1)==0)// For Move to Left & Clear Of Previous Place OF Rockets
        {
            gotoxy(x+1+table->getX(),i+table->getY());
            cout<<" ";
        }
    }
}

/*********************************************************************************/

void Rocket::move(bool up,bool right)
{
    //Up-Down
    if(up && !right && table->isInTable(y-1,x))//Move Rockets To UP
    {
        table->setElement(y+size-1,x,0);//Set 0 Previous Place OF Rockets
        table->setElement(y-1,x,4);//Set 4 Next Place OF Rockets
        y--;//Reduce OF Vertical Location Of Rocket
    }
    else if(!up && !right && table->isInTable(y+size,x))//Move Rockets To Down
    {
        table->setElement(y,x,0);//Set 0 Previous Place OF Rockets
        table->setElement(y+size,x,4);//Set 4 Next Place OF Rockets
        y++;//Increase OF Vertical Location Of Rocket
    }
    //Left-Right
    else if(up && right && (table->getElement(y,x-2)!=2 && table->getElement(y,x-2)!=5))//Move Rockets To Left
    {
        for(int i=0;i<size;i++)
        {
            table->setElement(y+i,x,0);//Set 0 Previous Place OF Rockets
            table->setElement(y+i,x-1,4);//Set 4 Next Place OF Rockets
        }
        x--;//Reduce OF Horizontal Location Of Rocket
    }
    else if(!up && right && (table->getElement(y,x+2)!=5 && table->getElement(y,x+2)!=3))//Move Rockets To Right
    {
        for(int i=0;i<size;i++)
        {
            table->setElement(y+i,x,0);//Set 0 Previous Place OF Rockets
            table->setElement(y+i,x+1,4);//Set 4 Next Place OF Rockets
        }
        x++;//Increase OF Horizontal Location Of Rocket
    }
}

/*********************************************************************************/
#endif // ROCKET_H
