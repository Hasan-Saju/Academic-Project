#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define si set<int>
#define FOR(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

struct node
{
    int data;
    node* next;
    node* prev;
};

node* DLLcreateNode(int val);
void DLLaddFirst(int val);
void DLLaddLast(int val);
int DLLfind(int val);
void DLLinsertAfter(int val,int neww);
void DLLinsertBefore(int val,int neww);
void DLLtraverse();
void DLLdelete(int value);//eita baki
void DLLsort();
void Print();




node* head;
node* tail;

node* DLLcreateNode(int val)//tested
{
    node* temp= new node;
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void DLLaddFirst(int val)//tested
{
    node* newNode=DLLcreateNode(val);
    if(head==NULL)//first node ekdom
    {
        head= newNode;
        tail=newNode;
        return;
    }
    //Age onno node ase
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}

void DLLaddLast(int val)
{
    node* newNode=DLLcreateNode(val);
    if(tail==NULL)
    {
        tail= newNode;
        head= newNode;
        return;
    }
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
}

int DLLfind(int val)
{
    node* temp= new node;
    temp=head;
    int kount=1;
    while(temp!=NULL)
    {
        if(temp->data==val)
            return kount;
        kount++;
        temp=temp->next;

        //koynumber a ase ber korbo
    }
    //cout<<"yup";
    return -1; //jodi na pai
}

void DLLinsertAfter(int val,int neww)
{
    node* newNode=DLLcreateNode(neww);
    node* temp= new node;
    node* porerta=new node;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            porerta=temp->next;
            newNode->prev=temp;
            newNode->next=temp->next;
            temp->next=newNode;
            porerta->prev=newNode;
            return;
        }
        temp=temp->next;
    }

    cout<<"not found for insert after"<<endl;  //jodi na pai
}

void DLLinsertBefore(int val,int neww)
{
    node* newNode=DLLcreateNode(neww);
    node* temp= new node;
    node* agerta=new node;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            agerta=temp->prev;
            newNode->next=temp;
            newNode->prev=temp->prev;
            temp->prev=newNode;
            agerta->next=newNode;

            return;
        }
        temp=temp->next;
    }

    cout<<"not found for insert after"<<endl;  //jodi na pai
}

void DLLsort()
{
    node *x,*y;
    x=head;
    for(x=head;x!=NULL;x=x->next)// 5 3 7 9 2 || 3 5 7 9 2|| 3 2 7 9 5
    {
        for(y=head;y!=NULL;y=y->next)
        {
            if((x->data)<(y->data))
            {
                swap(x->data,y->data);
            }
        }
    }
}

void DLLtraverse()
{
    node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void DLLdelete(int value)
{
    node* temp=head;
    node* agertay;
    node* porerta;
    while(temp->data!=value)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)//jodi last node hoy//eikhaneo shoman check kora uchit
    {
        agertay=temp->prev;
        agertay->next=NULL;
    }
   else  if(temp==head)//eikhaneo shoman check kora uchit
    {
        head=temp->next;
    }
    else
        {
             //jodi majhe hoy
           //  cout<<"majhe";
             //cout<<temp->data;
    agertay=temp->prev;
    porerta=temp->next;
    agertay->next=temp->next;
    porerta->prev=temp->prev;

        }

}

void Print()
{
    node* temp=head;
    cout<<"Here's the current list: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



