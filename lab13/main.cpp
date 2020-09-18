#include <iostream>
using namespace std;


void swap(int *array)
{
    int array1[16]={0};
    int a=0;
    int index0=0;
    int index=1;

    while(index<16)
    {

    if(array[index0]>array[index])
    {
        int a=array[index0];
        array[index0]=array[index];
        array[index]=a;
        index0=index;
    }
    if(array[index0]<array[index])
    {
        array1[a]=index;
        a++;

    }
        index++;

    }
    cout << index0<< "//" <<endl;

    for(int i=0;i<16;i++)
    {
        cout<<array1[i]<<endl;
    }


}





















void disp(int *array)
{
    for(int i=0;i<16;i++)
    {
        cout << array[i] << endl;
    }
}






int main()
{
    int array[16]={503,87,512,61,908,170,897,275,653,426,154,509,612,677,765,703};


    swap(array);


    //disp(array);








}
