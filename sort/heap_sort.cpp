#include <iostream>

using namespace std;


class heap{

int array[15];

int index=0;

int a=0;


public:
    heap()
    {
        for(int a=0;a<15;a++)
        {
            array[a]=-1;

        }
    }
void adder(int d);
void disp();
void checker(int index,int d);
void revchecker(int index);
void remove1(int index);
void forchecker(int index);
void dispsorted();
void remove();

};

void heap::remove1(int index)
{
    if(index>=0)
   { int i=array[0];



    array[0]=array[index];

    revchecker(index);
    forchecker(index);
    array[index]=i;

   }
}
void heap::remove()
{
    remove1(--index);

}












void heap::revchecker(int index)
{

    while(index!=0)
    {
        int a=(index-1)/2;

        if(array[a]<array[index])
        {
            int i=array[index];
            array[index]=array[a];
            array[a]=i;
        }
        index--;
    }
}

void heap::forchecker(int index1)
{
if(index1<=1){return;}

    int index=1;

    while(index !=index1)
    {
        int a=(index-1)/2;

        if(array[a]<array[index])
        {
            int i=array[index];
            array[index]=array[a];
            array[a]=i;
        }
        index++;
    }
}











void heap::checker(int index,int d)
{
int a=(index-1)/2;



if(array[a]<d)
{
    int i=array[index];
    array[index]=array[a];
    array[a]=i;


}






}






void heap::disp()
{
    for(int a=0;a<15;a++)
    {
        cout << array[a] << endl;
    }
}







void heap::adder(int d)
{
array[index]=d;

checker(index,d);
revchecker(index);
index++;

}






int main()
{
heap obj;
obj.adder(200);
obj.adder(1);
obj.adder(3000);
obj.adder(4000);
obj.adder(5);

obj.remove();
obj.remove();
obj.remove();
obj.remove();




obj.disp();








}








