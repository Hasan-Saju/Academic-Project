#include"MHSdll.h"
using namespace std;

int main()
{
    // fast
    int n,x,p,y;
    head=NULL;
    tail=NULL;
    cout<<"Welcome to Doubly Linked List"<<endl<<"How many numbers you want to add in the Doubly Linked List?: ";
    cin>>n;
    cout<<endl<<"First we will take the input with addFirst function."<<endl;
    FOR(i,n)
    {
        cout<<"Enter the number: ";
        cin>>x;
        DLLaddFirst(x);
        //DLLaddLast(x);
        Print();
    }
     cout<<endl<<"Now we will take the input with addLast function."<<endl;
     cout<<"How many number you want to take: ";
     cin>>n;
      FOR(i,n)
    {
        cout<<"Enter the number: ";
        cin>>x;
        DLLaddLast(x);
        //DLLaddLast(x);
        Print();
    }

    cout<<endl<<"Let's check the find function."<<endl<<"Which number you want to find: ";
    cin>>x;

    int findans=DLLfind(x);
    cout<<endl<<"Find the number in "<<findans<<" th Position"<<endl<<endl;

    cout<<"Let's check the Insert After function."<<endl<<"Which number you want to insert: ";
    cin>>x;
    cout<<"After which number: ";
    cin>>y;

    DLLinsertAfter(y,x);
    Print();

     cout<<endl<<"Let's check the Insert Before function."<<endl<<"Which number you want to insert: ";
    cin>>x;
    cout<<"Before which number: ";
    cin>>y;

    DLLinsertBefore(y,x);
   // cout<<endl<<"InsertBefore: ";
    Print();



    cout<<endl<<"Let's traverse the linked list: ";
    DLLtraverse();

    cout<<endl<<endl<<"Checking Sort function."<<endl<<"Sorted list is: ";
    DLLsort();
    DLLtraverse();


    cout<<endl<<endl<<"Let's check Delete function."<<endl<<"Which number you want to delete: ";
    cin>>x;
    DLLdelete(x);
    Print();


     cout<<endl<<endl<<"Let's check Delete function again."<<endl<<"Which number you want to delete: ";
    cin>>x;
    DLLdelete(x);
    Print();



}
