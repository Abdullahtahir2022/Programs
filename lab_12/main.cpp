#include <iostream>
using namespace std;





void display(int array[])
{
        for(int a=0;a<7;a++)
    {
        cout << array[a] << endl;
    }

}

void swap1(int *array)
{
int    index=0;
int    a,b,i=array[index];

    while(index<8)
    {

    if(i>array[index+1])
    {
         i=array[index+1];
         a=index+1;
    }

    index++;

    }
    b=array[0];
    array[0]=i;
    array[a]=b;

}

void swap3(int *array1,int *array2,int *array3)
{
    int index1=0;
    int index2=0;
    int index3=0;
    int s2=sizeof(array3)/sizeof(array3[0]);
    cout<<"asa:"<<s2<<endl;
    while(index3<s2)
    {


    if(array1[index1]<array2[index2])
    {
        array3[index3]=array1[index1];
        index1++;
        index3++;
    }
    if(array1[index1]>array2[index2])
    {
        array3[index3]=array2[index2];
        index2++;
        index3++;
    }


    }




}


















int main()
{
    //task 1
    //int array[7]={1,3,7,9,13,23,4};
    //swap(array);
    //display(array);

    //task 2
   // int    array[8]={74, 23, 17, 13, 7, 1, 9, 4};

   // swap1(array);
   // display(array);

   // task5
   //int array1[5]={1,12,3};
   //int array2[5]={6,7,9};
   //int array3[10];

   //swap3(array1,array2,array3);
   //display1(array3);

       //task 1
    /*int array[8]={4,7,12,9,13,23,4};



    for(int a=6;a>=0;a--)
   {

   swap(array,a);}


    display(array);*/


















}
