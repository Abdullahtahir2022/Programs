 #include<iostream>
 #include <fstream>
using namespace std;


class NODE{

int data;
NODE* next;

public:
    NODE(){
    data=0;
    next=NULL;
    }
    NODE(int dat)
    {
        data=dat;
        next=NULL;
    }

    void data1(int d){
    data=d;


    }
    void next1(NODE *n){
    next=n;

    }
    int getdata(){
    return data;}
     NODE* getnext(){
    return next;}

};

class linklist{

NODE* first;



public:
    linklist(){
first=NULL;
}
void adder(int d);
void remfend();
void remfstart();
void remindex(int d);
void getat(int d);
void addAtStart(int d);
void addindex(int d, int c);
void findindex(int d);
void remval(int d);
void Size();
void display();

};

 void linklist::adder(int d)
    {
        NODE *temp=new NODE(d);
        NODE *temp2=first;

        if(first==NULL)
        {
            first=temp;
            return;
        }
        else{

            while(temp2!=NULL)
            {


                if(temp2->getnext()==NULL)
                {

                    temp2->next1(temp);
                    break;
                }
                else{temp2=temp2->getnext();}




            }


        }


    }
 void linklist::remfstart(){

    first=first->getnext();

    }


void linklist::remfend()
    {

       NODE*temp=first;
       if(temp->getnext()==NULL || temp==NULL)
       {
           cout << "NO Node" << endl;

       }
    else
       if(temp->getnext()->getnext()==NULL)
       {
           temp->next1(NULL);
       }

       else{
        while(temp->getnext()->getnext()!=NULL)
        {
            temp=temp->getnext();
            if(temp->getnext()->getnext()==NULL){

                temp->next1(NULL);
                break;
            }


        }




       }



    }
void linklist::remindex(int d){
        NODE*temp=first;
        NODE*temp2;

        if(d==0)
        {
            first=temp->getnext();

        }
        else{

    for(int l=1;l<=d;l++)
    {
        temp2=temp;
        //this if for checking input more than node
        if(temp->getnext()==NULL){

                temp2->next1(NULL);
                break;
        }
        temp=temp->getnext();

    }


    temp2->next1(temp2->getnext()->getnext());}





    }



 void linklist::getat(int d){
        NODE*temp=first;
        NODE*temp2;

        if(d==0)
        {
            cout<<first->getdata()<<endl;

        }
        else{

    for(int l=1;l<=d;l++)
    {
        if(temp->getnext()!=NULL){
        temp=temp->getnext();}


    }

    cout<<temp->getdata() << endl;


        }

    }


void linklist :: addindex(int d, int c){
        NODE*temp=first;
        NODE*temp2;

        NODE*temp3=new NODE(c);

        if(d==0)
        {
           first=temp3;
           first->next1(temp);


        }
        else{

    for(int l=1;l<=d;l++)
    {
        temp2=temp;
        temp=temp->getnext();

    }

    temp2->next1(temp3);
    temp3->next1(temp);
        }



    }
void linklist::findindex(int d){
        NODE*temp=first;
        int x;

        int counter=0;



        if(first->getdata()==d)
        {
           cout<<"0"<<endl;
}
        else{

    while(temp->getdata()!=d)
    {


        counter++;

        if(temp->getnext()==NULL)
        {   x=-1;
            cout << x << endl;
            break;
        }
        temp=temp->getnext();


    }
if(x!=-1){
cout << counter << endl;}



    }


}

 void linklist::Size(){
        NODE*temp=first;


        int counter=0;

    while(2)
    {

        temp=temp->getnext();
        counter++;
        if(temp->getnext()==NULL)
        {

            break;
        }

    }


    cout<<++counter<<endl;}

void linklist::display()
    {
        NODE* temp=first;
        cout <<"----------------"<< endl;
        while(temp!=NULL)
        {

            cout<<temp->getdata()<<endl;
            temp=temp->getnext();


        }

    }


void linklist::addAtStart(int d)
    {

        NODE *temp= new NODE(d);
        NODE *temp2=first;

        first=temp;
        temp->next1(temp2);


    }
void linklist::remval(int d){


       NODE* temp=first;
       if(temp->getdata()==d)
       {
           first=temp->getnext();
       }
       else{
        while(2)
        {
            if(temp->getnext()->getdata()==d)
            {
                temp->next1(temp->getnext()->getnext());
                break;
            }
            else{temp=temp->getnext();}
        }

        }



       }

     void filehandle(){
     linklist obj1;
     string a;
     int c, counter=0,coun=0;




ifstream ab;
ab.open("data.txt");
while(!ab.eof())
{
    ab>>a;

    if(a=="A")
    {
        ab>>c;

        obj1.adder(c);
    }

    if(a=="AAS")
    {
        ab>>c;
        obj1.addAtStart(c);
    }
    if(a=="AT")
    {
        ab>>c;
        int b=c;
        ab>>c;
        obj1.addindex(b,c);
    }
    if(a=="D")
       {
           if(counter==0){
        obj1.display();
        counter++;
           }

       }
    if(a=="RFS")
        {
        obj1.remfstart();
        }
    if(a=="RA")
    {
        ab>>c;
        obj1.remindex(c);
    }
    if(a=="R")
    {
        ab>>c;
        obj1.remval(c);
    }
    if(a=="RFE")
    {
        obj1.remfend();
        coun++;
    }
    if(a=="D")
    {   if(coun==1)
            {

        obj1.display();}

    }



}
     }





























void template1()
{ linklist obj;
int b,c;
char a,x;

    cout << "Enter A to Add at Start" << endl;
    cout << "Enter B to Add at END" << endl;
    cout << "Enter C to Remove from Start" << endl;
    cout << "Enter D to Remove from END" << endl;
    cout << "Enter E to Remove the provided Value" << endl;
    cout << "Enter F to Remove by Index" << endl;
    cout << "Enter G to add value at specified index" << endl;
    cout << "Enter H to get value from specified index" << endl;
    cout << "Enter I to find the specified value and return the index" << endl;
    cout << "Enter J to get Size" << endl;
    cout << "Enter K to display" << endl;
    cout << "Enter Q to Quit" << endl;
do{

    cin>>a;

    switch(a)
    {
        case 'A':
        cout <<"Enter Data" << endl;
        cin>> b;
        obj.addAtStart(b);
        break;
        case 'B':
        cout <<"Enter Data" << endl;
        cin>> b;
        obj.adder(b);
        break;
        obj.adder(b);
        case 'C':
        obj.remfstart();
        break;
        case 'D':
        obj.remfend();
        break;
        case 'E':
        cout <<"Enter Data" << endl;
        cin>> b;
        obj.remval(b);
        break;
        case 'F':
        cout <<"Enter Index" << endl;
        cin>> b;
        obj.remindex(b);
        break;
        case 'G':
        cout <<"Enter Index" << endl;
        cin>> b;
        cout <<"Enter a Value" << endl;
        cin>>c;
        obj.addindex(b,c);
        break;
        case 'H':
        cout <<"Enter Index" << endl;
        cin>> b;
        obj.getat(b);
        break;
        case 'I':
        cout <<"Enter Value" << endl;
        cin>> b;
        obj.findindex(b);
        break;
        case 'J':
        obj.Size();
        break;
        case 'K':
        obj.display();
        break;
        default:
        break;
}
if(a!='Q')
   {cout << "Character again" << endl;}


}
while(a!='Q');





}
int main()
{
    int a;
cout << "Press 1 for File Handling" << endl;
cout << "Press 2 for Customizing Nodes" << endl;
cin>>a;
switch (a){
case 2:
template1();
break;
case 1:
filehandle();
default:
break;}

}
