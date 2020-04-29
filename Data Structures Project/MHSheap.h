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

int sizee=0;
void swap(int *a, int *b);
void MXHmaxHeapify(int arrayy[],int sizee,int i);
void MXHbuildMaxHeap(int arrayy[],int sizee);
int MXHheapSize();
void MXHheapPush(int arrayy[],int number);
void MXHheapPop(int arrayy[]);
void MXHheapSort(int arrayy[]);
void MXHtraverse(int arrayy[]);
void Print(int arrayy[]);




void swapp(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void MXHmaxHeapify(int arrayy[],int sizee,int i)//tested
{
    if(sizee==1)
    {
        cout<<"Not enough value to use max_heapify.";
    }
    else
        {
            int largest=i;
            int left=2*i+1;
            int right=2*i+2;
            if(left<sizee&&arrayy[left]>arrayy[largest])//<size because array starts from 0
            {
                largest=left;
            }
            if(right<sizee&&arrayy[right]>arrayy[largest])
            {
                largest=right;
            }
            if(largest!=i)//mane hocche largest ar amar pathano ta same node na
            {
                swapp(&arrayy[i],&arrayy[largest]);
              //  MXHmaxHeapify(arrayy,sizee,largest);
            }
        }
}

void MXHbuildMaxHeap(int arrayy[],int sizee)//tested
{
    for(int i=sizee/2-1;i>=0;i--)
    {
            MXHmaxHeapify(arrayy,sizee,i);
    }
}

int MXHheapSize()//tested
{
    return sizee;
}

void MXHheapPush(int arrayy[],int number)//number is the new number ,we wanna push
{
    if(sizee==0)
    {
        arrayy[0]=number;
        sizee+=1;
    }
    else
        {
            arrayy[sizee]=number;
    sizee+=1;
    MXHbuildMaxHeap(arrayy,sizee);
        }
}

void MXHheapPop(int arrayy[])//tested
{
    swapp(&arrayy[0],&arrayy[sizee-1]);
    sizee-=1;
    MXHbuildMaxHeap(arrayy,sizee);
}

void MXHheapSort(int arrayy[])
{
    MXHbuildMaxHeap(arrayy,sizee);
    for(int i=sizee;i>=0;i--)
    {
        swapp(&arrayy[0],&arrayy[i]);//ekdom last a niye gelam
        MXHbuildMaxHeap(arrayy,i-1);//erpor ekta kore last a niye jabo oitar ag porjonto build max heap chalabo
                                    //shobcheye booro ta last a ase
                                    //ascend order
    }
}

void MXHtraverse(int arrayy[])//tested
{
    //cout<<"tuki";
    for(int i=0;i<sizee;i++)
        cout<<arrayy[i]<<" ";
}

void Print(int arrayy[])
{
    //cout<<"tuki";
    for(int i=0;i<sizee;i++)
        cout<<arrayy[i]<<" ";
}



