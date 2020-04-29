#include"MHSheap.h"
using namespace std;
int main()
{

    //max heap
    int arrayy[100],n,i;
    cout<<"How many elements you want to insert: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
         cin>>arrayy[i];
         cout<<arrayy[i]<<" is inserted."<<endl;
    }

    sizee=n;
    MXHbuildMaxHeap(arrayy,sizee);
    cout<<endl<<"Checking Build MAX heap : ";
    Print(arrayy);
    cout<<endl;

    cout<<endl<<"Check Max heapify."<<endl<<"Give the index you want to perform max heapify: ";
    cin>>n;
    MXHmaxHeapify(arrayy,sizee,n);
    cout<<"After performing Max Heapify: ";
    Print(arrayy);

    // cout<<endl<<"Size is: "<<MXHheapSize();
    cout<<endl<<endl<<"Let's check Push function."<<endl<<"Give the number you want to push: ";
    cin>>n;
    MXHheapPush(arrayy,n);
    cout<<"After Push the heap looks like: ";
    Print(arrayy);

    cout<<endl<<endl<<"We will pop the top from the heap."<<endl;
    MXHheapPop(arrayy);
    cout<<"After pop the heap is now: ";
    Print(arrayy);

    cout<<endl<<endl<<"Here is the heap sort."<<endl;
    MXHheapSort(arrayy);
    cout<<"Sorted array: ";
    MXHtraverse(arrayy);

    //
}
