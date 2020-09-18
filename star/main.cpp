#include <iostream>

using namespace std;

void Shape4(char c,int l)
{
    int i,b;
    int e,d;
    for(i=1;i<=l;i++)
    {

        for(int j=1;j<=i;j++)
        {
            cout<<c;
        }

        for(int j=l;j>i;j--)
        {
            cout<<" ";
        }

        for(d=l;d>i;d--)
        {
            cout<<" ";
        }
        for(b=1;b<=i;b++)
        {
            cout<<c;
        }

        cout<<endl;


    }

}










int main()
{
Shape4('*',5);
}
