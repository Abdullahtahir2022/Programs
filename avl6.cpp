#include <iostream>
using namespace std;



class NODE{

int data;
NODE* left;
NODE* right;
int height;
public:
    NODE(){
    data=0;
    left=NULL;
    right=NULL;
    height=0;
    }
    NODE(int dat)
    {
        data=dat;
        left=NULL;
        right=NULL;
        height=0;
    }
    void height1(int h)
    {
        height=h;
    }
    int getheight()
    {
        return height;
    }

    void data1(int d){
    data=d;


    }
    void right1(NODE *n){
    right=n;

    }
    void left1(NODE *n)
   {

   left=n;}
    int getdata(){
    return data;}
     NODE* getright(){
    return right;}
    NODE* getleft(){
    return left;}

};
class AVL
{
   public:
       NODE* root;

       AVL()
       {
           root=NULL;
       }
       NODE* getroot()
       {
           return root;
       }
       void setroot(NODE* temp)
       {
           root=temp;
       }


NODE* adderrec(NODE* root, int d);
void disp_I(NODE* node);
int max(int a, int b);
int height(NODE* node);
int getbf(NODE* node);
void add(int d);
NODE* rotate_right(NODE* node);
NODE* rotate_left(NODE* node);
NODE* left_right(NODE* node);
NODE* right_left(NODE* node);
int search(NODE* node, int d);
NODE* remove(NODE* node,int d);
void last_value(NODE* node);
void last_value1(NODE* node);
int minvalue(NODE* node);
};
void AVL::last_value(NODE* node)
{
    NODE* node2=node;
    node=node->getleft();
    NODE* node1;


    while(node->getright()!=NULL)
    {   node1=node;
        node=node->getright();
    }
if(root->getdata()!=node2->getdata())
   {int a=node->getdata();
    cout << node2->getdata() << "---" << endl;
    node1->right1(NULL);
    node2->data1(a);}
else if(root->getdata()==node2->getdata())
{
    node->left1(root->getleft());
    node->right1(root->getright());
    root->left1(NULL);
    root->right1(NULL);
    root=node;
    node1->right1(NULL);

}

}

void AVL::last_value1(NODE* node)
{
    NODE* node2=node;
    node=node->getright();
    NODE* node1;

    while(node->getleft()!=NULL)
    {   node1=node;
        node=node->getleft();
    }
    int a=node->getdata();
    node1->left1(NULL);
    node2->data1(a);

}









NODE* AVL::rotate_right(NODE* node)
{



NODE* n2=node->getleft();
node->left1(n2->getright());
 n2->right1(node);
 n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
 node->height1(max(height(node->getleft()),height(node->getright()))+1);


 return n2;

}


NODE* AVL::left_right(NODE* node)
 {
   NODE* n2=node->getleft();

   node->left1(n2->getright());
   n2->right1(NULL);
   node->getleft()->left1(n2);


   return rotate_right(node);

}

NODE* AVL::right_left(NODE* node)
{

   NODE* n2=node->getright();

   node->right1(n2->getleft());
   n2->left1(NULL);
   node->getright()->right1(n2);


   return rotate_left(node);

}






















NODE* AVL::rotate_left(NODE* node)
{



NODE* n2=node->getright();
node->right1(n2->getleft());
n2->left1(node);
n2->height1(max(height(n2->getleft()),height(n2->getright()))+1);
node->height1(max(height(node->getleft()),height(node->getright()))+1);


return n2;

}


int AVL:: search(NODE* node, int d)
{

    if (node->getdata()==d)
       return node->getdata();


    if (node->getdata()<d)
    return search(node->getright(), d);



    return search(node->getleft(), d);
}
int AVL::minvalue(NODE* node)
{


    while(node->getleft()!=NULL)

       {node=node->getleft();}

    return node->getdata();
}

NODE* AVL:: remove(NODE* root, int d)
{
    if(root==NULL)
    {
    return root;
    }

    if(d<root->getdata())
    {
        root->left1(remove(root->getleft(),d));

    }





     else if(d>root->getdata())
    {
        root->right1(remove(root->getright(),d));

    }

    else{


    if(root->getleft()==NULL && root->getright()!=NULL)
    {
     root=root->getright();

    }

    if(root->getright()==NULL && root->getleft()!=NULL)
    {

        root=root->getleft();

    }

    if(root->getleft()==NULL && root->getright()==NULL)
    {

        delete(root);
        root=NULL;
    }


    else if(root->getleft()!=NULL && root->getright()!=NULL)

    {   int a=minvalue(root->getright());
        root->data1(a);
        root->right1(remove(root->getright(),a));
    }


    }

 if(root==NULL)
 {
     return root;
 }



root->height1(max(height(root->getleft()),height(root->getright()))+1);

int b=getbf(root);
if (b > 1 &&  getbf(root->getleft()) >= 0)
        {return rotate_right(root);}
if (b > 1 &&  getbf(root->getleft()) < 0)
        {return left_right(root);}
if (b < -1 &&  getbf(root->getright()) <= 0)
        {return rotate_left(root);}
if (b < -1 &&  getbf(root->getright()) > 0)
        {return right_left(root);}


















return root;



}










int AVL::getbf(NODE* node)
{
  return     height(node->getleft())-height(node->getright());
}



int AVL::max(int a, int b)
{
    if(a>b)
    {return a;}
    else if(a<b){return b;}
    else{return b;}
}

int AVL::height(NODE* node)
{
    if(node==NULL)
    {
        return -1;
    }
   else
   {return node->getheight();}
}

void AVL::disp_I(NODE* temp2)
{

    if(temp2==NULL)
        return;
    else
    {

         disp_I(temp2->getleft());
         cout << temp2->getdata() << endl;

         disp_I(temp2->getright());

    }
}

void AVL:: add(int d)
{
    setroot(adderrec(root,d));
}







NODE* AVL::adderrec(NODE* temp2,int d)
{

    if(temp2==NULL)
    {
         temp2=new NODE(d);
    }
    else if(d<temp2->getdata())
        {

            temp2->left1(adderrec(temp2->getleft(),d));

            int bf=getbf(temp2);
            if(bf==2 || bf==-2)
            {
                if(d<temp2->getleft()->getdata())
                {
                   temp2=rotate_right(temp2);
                }
                if(d>temp2->getleft()->getdata())
                {

                   temp2=left_right(temp2);

                }

            }


        }
  else if(d>temp2->getdata())
        {

             temp2->right1(adderrec(temp2->getright(),d));
            int bf=getbf(temp2);
            if(bf==2 || bf==-2)
            {   ;
                if(d>=temp2->getright()->getdata())
                {
                   temp2=rotate_left(temp2);
                }
                if(d<temp2->getright()->getdata())
                {

                   temp2=right_left(temp2);

                }
            }
        }


temp2->height1(max(height(temp2->getleft()),height(temp2->getright()))+1);
return temp2;




}
























int main()
{
   AVL obj;




  obj.add(100);
  obj.add(120);
  obj.add(115);
  obj.add(122);
  obj.add(121);
  obj.add(123);
  obj.add(90);
  obj.add(90);
  obj.add(91);
  obj.add(93);
  obj.add(93);



//obj.remove(obj.getroot(),91);
obj.disp_I(obj.getroot());









}

