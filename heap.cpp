
#include<iostream>
using namespace std;


int main()
{

int array[15]={160,140,100,80,70,90,30,20,40,10,60,190,35,45,120};



for(int i=0;i<15;i++)
{
    if(array[i]>array[(2*i)+1] && array[i]>array[(2*i)+2])
    {
       cout << "ok" << endl;

    }
    else
    {
        cout << "Not" << endl;
        cout << "i" << array[i] << "l" << array[(2*i)+1] << "r" << array[(2*i)+2] << endl;
        break;
    }
}








}
